/*
** EPITECH PROJECT, 2023
** my_teams_tmp
** File description:
** utils
*/

#include "../include/my_teams.h"

int is_number(const char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] < '0' || str[i] > '9')
            return (0);
        i++;
    }
    return (1);
}

char *my_read(int fd)
{
    char *buff = malloc(sizeof(char) * 1024);
    int size = 0;
    int i = 0;

    if (buff == NULL)
        return (NULL);
    while ((size = read(fd, buff + i, 1024)) > 0) {
        i += size;
        buff = realloc(buff, sizeof(char) * (i + 1024));
    }
    buff[i] = '\0';
    return (buff);
}

void error_handling(const char *str)
{
    printf("%s\n", str);
    exit(FAILURE);
}
