/*
** EPITECH PROJECT, 2023
** my_teams_tmp
** File description:
** my
*/

#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <limits.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <stdarg.h>
#include <sys/time.h>
#include <sys/types.h>
#include <errno.h>
#include <dirent.h>

#define FAILURE 84
#define BUFSIZE 1024

#define MAX_NAME_LENGTH 32
#define MAX_DESCRIPTION_LENGTH 255
#define MAX_BODY_LENGTH 512
#define MAX_CLIENTS 30

typedef struct server_s{
    struct sockaddr_in sockaddr;
    int fd;
    int port;
    size_t addrlen;
    fd_set readfds;
    int client_skt[30];
    int max_clients;
    char *username;
    char *password;
    char *path;
    int csd;
    int fd_max;
    int log;
} server_t;


void loop(server_t *server);
void error_handling(const char *str);
server_t *init_server(const char **av);
void create_client(server_t *server);
void get_cmd(server_t *server);
void print_help(void);
int is_number(const char *str);
void user(server_t *server, char *cmd);
int my_strcmp(char *s1, char *s2);
char *get_second(char *cmd);
int check_dir(char *path);
void set_fd(int i, server_t *server);
void check_client(server_t *server, int new_socket);


struct cmd {
    const char cmd[5];
    void (*func)(server_t *, char *);
};

typedef struct command_s {
    char *name;
    int (*func)(server_t *client, char **args);
} command_t;


int cmd_help(server_t *client, char **args);
int cmd_login(server_t *client, char **args);
int cmd_logout(server_t *client, char **args);
int cmd_users(server_t *client, char **args);
int cmd_user(server_t *client, char **args);
int cmd_send(server_t *client, char **args);
int cmd_messages(server_t *client, char **args);
int cmd_subscribe(server_t *client, char **args);
int cmd_subscribed(server_t *client, char **args);
int cmd_unsubscribe(server_t *client, char **args);
int cmd_use(server_t *client, char **args);
int cmd_create(server_t *client, char **args);
int cmd_list(server_t *client, char **args);
int cmd_info(server_t *client, char **args);

static const struct cmd cmd_atgs[] = {
    {"help", &cmd_help},
    {"login", &cmd_login},
    {"logout", &cmd_logout},
    {"users", &cmd_users},
    {"user", &cmd_user},
    {"send", &cmd_send},
    {"messages", &cmd_messages},
    {"subscribe", &cmd_subscribe},
    {"subscribed", &cmd_subscribed},
    {"unsubscribe", &cmd_unsubscribe},
    {"use", &cmd_use},
    {"create", &cmd_create},
    {"list", &cmd_list},
    {"info", &cmd_info},
    {NULL, NULL}
};
