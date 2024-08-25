#ifndef BOARD_H
#define BOARD_H

#define EMPTY_BLOCK_CHAR 32 
#define FULL_BLOCK_CHAR 35

typedef struct Board
{
    int Width;
    int Height;
    unsigned char** Content;
} Board;

int CreateBoard(const int width, const int height, Board* b);

int LoadPlayerInput(Board* b);

void ShowBoard(Board* b);

void DisposeBoard(Board* b);

#endif // !BOARD_H
