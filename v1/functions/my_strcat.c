/*
** EPITECH PROJECT, 2023
** strcat
** File description:
** strcat
*/

#include "../include/my_teams.h"

char *my_superstrcat(char *dest, char const *src)
{
    int i = 0;
    int j = 0;
    char *str = malloc(sizeof(char) * (strlen(dest) + strlen(src) + 1));

    if (str == NULL)
        return (NULL);
    while (dest[i] != '\0') {
        str[i] = dest[i];
        i++;
    }
    while (src[j] != '\0') {
        str[i] = src[j];
        i++;
        j++;
    }
    str[i] = '\0';
    return (str);
}
