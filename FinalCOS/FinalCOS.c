#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ROWS 6
#define COLS 6

/*
Starting fresh for the final since my head is spaghettified from trying to remember everything from
the other assignments
*/

typedef struct ROOM {
    char name[50];
} ROOM;

// Make 2D array room room
ROOM** createRooms() {
    ROOM** rooms = (ROOM**)malloc(ROWS * sizeof(ROOM*));
    for (int i = 0; i < ROWS; i++) {
        rooms[i] = (ROOM*)malloc(COLS * sizeof(ROOM));
    }

    // Initialize room names (sticking numerical for now, nothing fancy)
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            sprintf(rooms[i][j].name, "Room %d-%d", i + 1, j + 1);
        }
    }

    return rooms;
}

// Show which way out
void printRoomExits(ROOM** rooms, int row, int col) {
    printf("Room: %s\n", rooms[row][col].name);

    if (row > 0) {
        printf("North: %s\n", rooms[row - 1][col].name);
    }
    if (row < ROWS - 1) {
        printf("South: %s\n", rooms[row + 1][col].name);
    }
    if (col > 0) {
        printf("West: %s\n", rooms[row][col - 1].name);
    }
    if (col < COLS - 1) {
        printf("East: %s\n", rooms[row][col + 1].name);
    }
    printf("\n");
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
                printf(" %c-%c ", rooms[i][j].name[5], rooms[i][j].name[7]); // Print the super original room names
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
    ROOM** rooms = createRooms();


    int currentRow = 0; // Keep track of current position
    int currentCol = 0;

    char command[10];
    char direction;

    while (1) {
        printMap(rooms, currentRow, currentCol);
        printf("You are in %s.\n", rooms[currentRow][currentCol].name);
        printRoomExits(rooms, currentRow, currentCol);

        printf("\nEnter command (e.g., 'move n'): ");
        scanf("%s", command);

        if (strcmp(command, "move") == 0) {
            scanf(" %c", &direction);
            move(&currentRow, &currentCol, direction);
        } else {
            printf("Invalid command!\n");
        }
    }

    // Be free!
    for (int i = 0; i < ROWS; i++) {
        free(rooms[i]);
    }
    free(rooms);

    return 0;
}