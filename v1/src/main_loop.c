/*
** EPITECH PROJECT, 2023
** loop
** File description:
** loop
*/

#include "my_teams.h"
#include "server.h"
#include "command.h"

int main_loop(server_t *server)
{
    char *buffer = NULL;
    char **args = NULL;
    size_t size = 0;
    int i = 0;

    while (1) {
        if (getline(&buffer, &size, stdin) == -1)
            return (0);
        buffer[strlen(buffer) - 1] = '\0';
        args = str_to_word_array(buffer, " ");
        for (i = 0; cmd[i].name != NULL; i++) {
            if (strcmp(cmd[i].name, args[0]) == 0) {
                cmd[i].func(server, args);
                break;
            }
        }
        if (cmd[i].name == NULL)
            printf("Unknown command '%s' try 'help'.\r ", args[0]);
        free(buffer);
        free(args);
        buffer = NULL;
        args = NULL;
    }
    return (0);
}