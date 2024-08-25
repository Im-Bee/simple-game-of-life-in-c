#include "Board.h"
#include "GameLogic.h"

#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif // _WIN32

#define BOARD_SIZE_W 80
#define BOARD_SIZE_H 16

#ifdef _WIN32
#define GAME_UPDATE_LATENCY 125
#else
#define GAME_UPDATE_LATENCY (125 * 1000)
#endif

int main()
{
    Board myBoard;
    Board backBoard;

    if (!CreateBoard(BOARD_SIZE_W,
        BOARD_SIZE_H,
        &myBoard))
        return -1;

    if (!CreateBoard(BOARD_SIZE_W,
        BOARD_SIZE_H,
        &backBoard))
        return -1;

    LoadPlayerInput(&myBoard);

    for (;;)
    {
        ShowBoard(&myBoard);
        UpdateGame(&myBoard, &backBoard);

        #ifdef _WIN32
        Sleep(GAME_UPDATE_LATENCY);
        #else
        usleep(GAME_UPDATE_LATENCY);
        #endif // _WIN32
    }

    DisposeBoard(&myBoard);
    DisposeBoard(&backBoard);
}
