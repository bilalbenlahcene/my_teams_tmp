/*
** EPITECH PROJECT, 2023
** my_teams_tmp
** File description:
** init
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

void create_client(server_t *server)
{
    int new_socket = 0;
    if (FD_ISSET(server->fd, &server->readfds)) {
        new_socket = accept(server->fd, (struct sockaddr *)&server->sockaddr,
            (socklen_t*)&server->addrlen);
        write(new_socket, "220 Service ready\n", 18);
        check_client(server, new_socket);
    }
}

int check_dir (char *path)
{
    DIR *dirptr;

    if (access ( path, F_OK ) != -1 ) {
        if ((dirptr = opendir (path)) != NULL)
            closedir (dirptr);
        else
            return (1);
    }
    else
        return (1);
    return (0);
}

void set_fd(int i, server_t *server)
{
    if (server->client_skt[i] != 0)
        FD_SET(server->client_skt[i], &server->readfds);
    if (server->client_skt[i] > server->fd_max)
        server->fd_max = server->client_skt[i];
    return;
}

void check_client(server_t *server, int new_socket)
{
    for (int i = 0; i < server->max_clients; i++) {
        if (server->client_skt[i] == 0 )  {
            server->client_skt[i] = new_socket;
            break;
        }
    }
    return;
}
