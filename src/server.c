/*
** EPITECH PROJECT, 2023
** server
** File description:
** server
*/

#include "server.h"

int init_server(server_t *server, int port)
{
    server->port = port;
    server->socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server->socket == -1) {
        perror("socket");
        return (84);
    }
    server->server.sin_family = AF_INET;
    server->server.sin_port = htons(port);
    server->server.sin_addr.s_addr = INADDR_ANY;
    if (bind(server->socket, (struct sockaddr *)&server->server, sizeof(server->server)) == -1) {
        perror("bind");
        return (84);
    }
    if (listen(server->socket, server->port) == -1) {
        perror("listen");
        return (84);
    }
    return (0);
}

int server_connect(server_t *server)
{
    int client_socket = 0;
    struct sockaddr_in client;
    socklen_t client_size = sizeof(client);

    client_socket = accept(server->socket, (struct sockaddr *)&client, &client_size);
    if (client_socket == -1) {
        perror("accept");
        return (84);
    }
    return (client_socket);
}
