/*
** EPITECH PROJECT, 2023
** my_teams_tmp
** File description:
** main
*/

#include "../include/my_teams.h"

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
