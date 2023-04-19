/*
** EPITECH PROJECT, 2023
** server
** File description:
** server
*/

#pragma once

#include "my_teams.h"

typedef struct server_s {
    int port;
    char *user;
    char *description;
    char *path;
    int socket;
    int max_fd;
    fd_set read_fds;
    fd_set write_fds;
    fd_set active_read_fds;
    fd_set active_write_fds;
    struct sockaddr_in server;
    struct sockaddr_in client;
    socklen_t client_size;
} server_t;
