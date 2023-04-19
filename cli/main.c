/*
** EPITECH PROJECT, 2023
** main_cli
** File description:
** main_cli
*/

#include "../include/my_teams.h"

int main(int ac, char **av)
{
    int sock = 0;
    int valread;
    struct sockaddr_in serv_addr;
    char *mess = "Hello from client";
    char *buffer = malloc(sizeof(char) * 1024);
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("\n Socket creation failed\n");
        return -1;
    }
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(atoi(av[1]));
    if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0) {
        printf("\nInvalid address not supported \n");
        return -1;
    }
    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("\nConnection Failed \n");
        return -1;
    }
    send(sock, mess, strlen(mess), 0);
    printf("Hello message\n");
    valread = read(sock, buffer, 1024);
    printf("%s\n", buffer);
    return 0;
}