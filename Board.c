#include "Board.h"

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

int CreateBoard(const int width, const int height, Board* b)
{
    // Just to be safe
    if (width < 1 || height < 1)
        return 0;

    b->Height = height;
    b->Width = width;

    unsigned char** tmpContentPtr = (unsigned char**) malloc(sizeof(unsigned char*) * height);

    if (!tmpContentPtr)
        return 0;

    for (int i = 0; i < height; i++)
    {
        tmpContentPtr[ i ] = (unsigned char*) malloc(sizeof(unsigned char) * width);

        if (!tmpContentPtr[ i ])
            return 0;

        for (int j = 0; j < width; j++)
            tmpContentPtr[ i ][ j ] = 0;
    }

    b->Content = tmpContentPtr;

    return 1;
}

int LoadPlayerInput(Board* b)
{
    // DEBUG
    {
        b->Content[ 2 ][ 2 ] = 1;
        b->Content[ 2 ][ 4 ] = 1;
        b->Content[ 3 ][ 3 ] = 1;
        b->Content[ 3 ][ 1 ] = 1;
        b->Content[ 2 ][ 2 ] = 1;
        b->Content[ 2 ][ 3 ] = 1;
        b->Content[ 2 ][ 4 ] = 1;
        b->Content[ 3 ][ 2 ] = 1;
        b->Content[ 3 ][ 3 ] = 1;
        b->Content[ 4 ][ 2 ] = 1;
        b->Content[ 4 ][ 4 ] = 1;
        b->Content[ 3 ][ 5 ] = 1;
        b->Content[ 3 ][ 4 ] = 1;
        b->Content[ 2 ][ 5 ] = 1;
        b->Content[ 2 ][ 6 ] = 1;
    }

    return 0;
}

void ShowBoard(Board* b)
{
    // Clear the terminal
    #ifdef _WIN32
    system("cls");
    #else
    system("clear");
    #endif // _WIN32

    static unsigned char boardCharBuff[ 2048 ] = { 0 };

    int charIndx = 0;
    // unsigned char shownChar;
    for (int i = 0; i < b->Height; i++)
    {
        for (int j = 0; j < b->Width; j++)
        {
            // if (b->Content[ i ][ j ])
            //     shownChar = FULL_BLOCK_CHAR;
            // else
            //     shownChar = EMPTY_BLOCK_CHAR;
            //
            // printf("%c", shownChar);

            boardCharBuff[ charIndx++ ] = b->Content[i][j] ? FULL_BLOCK_CHAR : EMPTY_BLOCK_CHAR;
        }
        // printf("\n");

        boardCharBuff[ charIndx++ ] = '\n';
    }

    boardCharBuff[ charIndx ] = '\0';
    printf("%s", boardCharBuff);
}

void DisposeBoard(Board* b)
{
    for (int i = 0; i < b->Height; i++)
        free(b->Content[ i ]);

    free(b->Content);
}
