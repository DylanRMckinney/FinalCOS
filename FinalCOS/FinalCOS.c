#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "roomFuncs.h"

/*
Starting fresh for the final since my head is spaghettified from trying to remember everything from
the other assignments
*/

// Struct moved to roomFuncs.h



/* Removed printRoomExits since the map shows where you are, and given an error if trying to
walk into a wall
*/


// Move around!
void move(int* row, int* col, char direction) {
    switch (direction) {
        case 'n':
            if (*row > 0) {
                (*row)--;
            }
            else {
                printf("\nNo exit that way; you're walking into a wall!\n"); // Take 100% damage from concussion from wall
            }
            break; // Break spine
        case 's':
            if (*row < ROWS - 1) {
                (*row)++;
            }
            else {
                printf("\nNo exit that way; you're walking into a wall!\n");
            }
            break;
        case 'w':
            if (*col > 0) {
                (*col)--;
            }
            else {
                printf("\nNo exit that way; you're walking into a wall!\n");
            }
            break;
        case 'e':
            if (*col < COLS - 1) {
                (*col)++;
            }
            else {
                printf("\nNo exit that way; you're walking into a wall!\n");
            }
            break;
        default:
            fprintf(stderr, "\nInvalid direction: %c\n", direction); // Make sure user is using n/e/w/s
    }
}

int main() {
    

    int score = 0;
    int totalPickups = 0;

    while (1) {
        ROOM** rooms = createRooms();

    // Keep track of pickups
    for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                if (rooms[i][j].roomContents == 'P') {
                    totalPickups++;
                }
            }
    }


    int currentRow = 0; // Keep track of current position
    int currentCol = 0;

    char command[10];
    char direction;

    while (totalPickups > 0) {
        printMap(rooms, currentRow, currentCol);

        printf("Score: %d\n", score);
        

        printf("\nEnter command (e.g., 'move n'): ");
        scanf("%s", command);

        if (strcmp(command, "move") == 0) {
            scanf(" %c", &direction);
            move(&currentRow, &currentCol, direction);

            if (rooms[currentRow][currentCol].roomContents == 'P') {
                    printf("You found a pickup!\n");
                    rooms[currentRow][currentCol].roomContents = ' '; // Remove pickup
                    score++;
                    totalPickups--;
             }
        } else {
            printf("Invalid command!\n");
        }
    }



    // Be free!
    for (int i = 0; i < ROWS; i++) {
        free(rooms[i]);
    }
    free(rooms);
    }

    return 0;
}