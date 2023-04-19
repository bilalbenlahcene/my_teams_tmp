/*
** EPITECH PROJECT, 2023
** main_server
** File description:
** main_server
*/

#include "../include/my_teams.h"

server_t *init_server(const char **av)
{
    server_t *server = malloc(sizeof(server_t));
    int opt = 1;

    server->fd = socket(PF_INET, SOCK_STREAM, 0);
    if (server->fd == -1)
        error_handling("socket error");
    server->sockaddr.sin_family = AF_INET;
    server->sockaddr.sin_port = htons(atoi(av[1]));
    server->addrlen = sizeof(server->sockaddr);
    if (setsockopt(server->fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt,
                   sizeof(opt)))
        error_handling("setsockopt error");
    if (bind(server->fd, (struct sockaddr *)&server->sockaddr,
             sizeof(server->sockaddr)) < 0)
        error_handling("bind error");
    if (listen(server->fd, 5) == -1)
        error_handling("listen error");
    server->port = atoi(av[1]);
    return (server);
}

int main(int ac, char **av)
{
    server_t *server = init_server(av);
    int max_sd = 0;
    int activity = 0;
    int i = 0;
    int valread;

    if (check_dir("data") == 1)
        error_handling("data directory not found");
    FD_ZERO(&server->readfds);
    FD_SET(server->fd, &server->readfds);
    max_sd = server->fd;
    while (1) {
        FD_ZERO(&server->readfds);
        FD_SET(server->fd, &server->readfds);
        activity = select(max_sd + 1, &server->readfds, NULL, NULL, NULL);
        if ((activity < 0) && (errno != EINTR))
            error_handling("select error");
        create_client(server);
        for (i = 0; i < MAX_CLIENTS; i++) {
            if (FD_ISSET(server->client_skt[i], &server->readfds)) {
                if (get_client(server, i) == 0) {
                    close(server->client_skt[i]);
                    server->client_skt[i] = 0;
                }
            }
        }
    }
    return (0);
}