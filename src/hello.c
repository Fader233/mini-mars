#include <stdio.h>
#include "hello.h"

int getAge(){
    return 18;
}

void ChangeDirect(int move[2], char direction)
{
    if (direction == 'N') {
        move[0] = 0;
        move[1] = 1;
    }
    if (direction == 'S') {
        move[0] = 0;
        move[1] = -1;
    }
    if (direction == 'E') {
        move[0] = 1;
        move[1] = 0;
    }
    if (direction == 'W') {
        move[0] = -1;
        move[1] = 0;
    }
    return;
}

void MarsCar(int locate[2], char *direction, char *commands)
{
    int ptr = 0;
    int move[2] = ChangeDirect(move, *direction);
    char dirdict[] = {'N','E','S','W'};
    int idx = 0;
    for (idx = 0; idx < 4; idx++) {
        if (dirdict[idx] == *direction) {
            break;
        }
    }

    while (commands[ptr] != '\0') {
        if (commands[ptr] != 'M') {
            if (commands[ptr] == 'R') {
                idx = (idx + 1) % 4;
            } else {
                idx = (idx - 1) % 4;
            }
            *direction = dirdict[idx];
            move = ChangeDirect(move, *direction)
        } else {
            locate[0] += move[0];
            locate[1] += move[1];
        }
    }
    return;
}