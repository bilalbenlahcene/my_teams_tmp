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
#include <dirent.h>

#define FAILURE 84
#define BUFSIZE 1024
#define

// return types
typedef struct {
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
void pass(server_t *server, char *cmd);
void pwd(server_t *server, char *cmd);
void quit(server_t *server, char *cmd);
void help(server_t *server, char *cmd);
int my_strcmp(char *s1, char *s2);
char *get_second(char *cmd);
void help(server_t *server, char *cmd);
void noop(server_t *server, char *cmd);
int check_dir(char *path);
void set_fd(int i, server_t *server);
void check_client(server_t *server, int new_socket);
void cwd(server_t *server, char *cmd);


struct cmd {
    const char cmd[5];
    void (*func)(server_t *, char *);
};

static const struct cmd cmd_atgs[] = {
    {"USER", &user},
    {"PASS", &pass},
    {"PWD", &pwd},
    {"QUIT", &quit},
    {"HELP", &help},
    {"NOOP", &noop},
    {"CWD", &cwd}
};
