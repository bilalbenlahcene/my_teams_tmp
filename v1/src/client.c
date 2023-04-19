/*
** EPITECH PROJECT, 2023
** client
** File description:
** client
*/

#include "../include/server.h"

int init_client(server_t *client, int port)
{
    client->port = port;
    client->socket = socket(AF_INET, SOCK_STREAM, 0);
    if (client->socket == -1) {
        perror("socket");
        return (84);
    }
    client->server.sin_family = AF_INET;
    client->server.sin_port = htons(port);
    client->server.sin_addr.s_addr = INADDR_ANY;
    if (connect(client->socket, (struct sockaddr *)&client->server, sizeof(client->server)) == -1) {
        perror("connect");
        return (84);
    }
    return (0);
}

