#ifndef ROOM_FUNCS_H
#define ROOM_FUNCS_H


#define ROWS 8
#define COLS 8

typedef struct ROOM ROOM;

struct ROOM{
    char roomContents; // Either empty or has a shiney pickup
    char name[3];
};

ROOM** createRooms();
void printMap(ROOM** rooms, int currentRow, int currentCol);

#endif