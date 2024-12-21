#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "roomFuncs.h"


// Make 2D array room room
ROOM** createRooms() { 
    ROOM** rooms = (ROOM**)malloc(ROWS * sizeof(ROOM*));
    for (int i = 0; i < ROWS; i++) {
        rooms[i] = (ROOM*)malloc(COLS * sizeof(ROOM));
    }

    // Now initializing rooms as empty unless including a pickup to avoid clutter
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            rooms[i][j].roomContents = ' ';
        }
    }

    // Spawn pickups in 10% to 50% of rooms
    srand(time(NULL)); // Seed the random number generator
    int numPickups = (rand() % 5 + 1) * (ROWS * COLS) / 10;

    for (int i = 0; i < numPickups; i++) {
        int row = rand() % ROWS;
        int col = rand() % COLS;
        rooms[row][col].roomContents = 'P';
    }

    return rooms;
}

// Print map map
void printMap(ROOM** rooms, int currentRow, int currentCol) {
    printf("\nMap:\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (i == currentRow && j == currentCol){
                printf(" *** "); // This is you
            } 
            else {
                printf("  %c  ", rooms[i][j].roomContents); // Print the super original room names
            }
            if (j < COLS - 1) {
                printf("|");
            }
        }
        printf("\n");
        if (i < ROWS - 1) {
            for (int j = 0; j < COLS; j++) {
                printf("-----"); // Should fit nice and perfectly now
                if (j < COLS - 1) {
                    printf("+");
                }
            }
            printf("\n");
        }
    }
    printf("\n");
}