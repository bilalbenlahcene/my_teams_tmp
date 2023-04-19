/*
** EPITECH PROJECT, 2023
** my_teams_tmp
** File description:
** user
*/

#include "../../include/my_teams.h"

int my_strcmp(char *s1, char *s2)
{
    int i = 0;

    while (s1[i] != '\0' && s2[i] != '\0') {
        if (s1[i] != s2[i])
            return (0);
        i++;
    }
    if (s1[i] == '\0' && s2[i] == '\0')
        return (1);
    return (0);
}

void user(server_t *s, char *cmd)
{
    char *username = malloc(sizeof(char) * 1024);
    username = get_second(cmd);
    if (username == NULL)
        write(s->client_skt[s->csd], "530 Please specify the username\n",
            32);
    else if (my_strcmp(username, "Anonymous") != 0 ) {
        s->username = username;
        s->log = 1;
        write(s->client_skt[s->csd], "username saved\n",
            32);
    } else
        write(s->client_skt[s->csd], "331 Please specify the password\n",
            32);
}
