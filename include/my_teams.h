/*
** EPITECH PROJECT, 2023
** teams
** File description:
** teams
*/

#pragma once

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <dirent.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/select.h>
#include <sys/time.h>

#define MAX_NAME_LENGHT 32
#define MAX_DESCRIPTION_LENGHT 255
#define MAX_BODY_LENGHT 512

typedef struct my_teams_s {
    int port;
    char *user;
    char *description;
    char *path;
} my_teams_t;
