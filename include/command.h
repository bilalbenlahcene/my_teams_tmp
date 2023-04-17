/*
** EPITECH PROJECT, 2023
** command
** File description:
** command
*/

#include "my_teams.h"
#include "server.h"

typedef struct command_s {
    char *name;
    int (*func)(server_t *client, char **args);
} command_t;

static const struct command_s cmd[] = {
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
