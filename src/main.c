/*
** EPITECH PROJECT, 2023
** my_teams_tmp
** File description:
** main
*/

#include "my.h"

void command(server_t *s, char *str)
{
    for (int i = 0; i < 7; i++) {
        if (strncmp(str, cmd_atgs[i].cmd, strlen(cmd_atgs[i].cmd)) == 0) {
            cmd_atgs[i].func(s, str);
            return;
        }
    }
    write(s->client_skt[s->csd], "500 Syntax error, command unrecognized.\n"
        , 40);
}

void get_cmd(server_t *server)
{
    char *buffer = malloc(sizeof(char) * BUFSIZE);
    int valread = 0;
    for (int i = 0; i < server->max_clients; i++) {
        memset(buffer, 0, BUFSIZE);
        if (FD_ISSET(server->client_skt[i] , &server->readfds)) {
            valread = read(server->client_skt[i], buffer, BUFSIZE);
            if (valread <= 0) {
                close(server->client_skt[i]);
                server->client_skt[i] = 0;
            } else {
                buffer[valread] = '\0';
                server->csd = i;
                command(server, buffer);
            }
        }
    }
}

void loop(server_t *server)
{
    int client_fd, activity, new_socket, valread;
    char *cmd = malloc(sizeof(char) * BUFSIZE);
    server->fd_max = server->fd;
    while (1) {
        FD_ZERO(&server->readfds);
        FD_SET(server->fd, &server->readfds);
        for (int i = 0; i < server->max_clients; i++)
            set_fd(i, server);
        activity = select(server->fd_max + 1, &server->readfds, NULL, NULL,
        NULL);
        if (activity < 0)
            error_handling("select error");
        create_client(server);
        get_cmd(server);
    }
    free(cmd);
}

void print_help(void)
{
    printf("USAGE\n\t./my_ftp port path\n\t");
    printf("port is the port number on which the server socket listens\n\t");
    printf("path is the path to the home directory for the Anonymous user\n");
}

int main(int ac, const char **av)
{
    if (ac == 2 && strcmp(av[1], "-help") == 0)
        print_help();
    if (ac != 3 || is_number(av[1]) == 0 || check_dir(av[2]) == 1)
        error_handling("Usage: ./my_ftp port path\n");
    server_t *server = malloc(sizeof(server_t));
    server = init_server(av);
    server->max_clients = 30;
    for (int i = 0; i < server->max_clients; i++)
        server->client_skt[i] = 0;
    server->path = av[2];
    server->log = 0;
    server->username = NULL;
    printf("[+] Server started on port %d\n", server->port);
    loop(server);
    free(server);
    return (0);
}
