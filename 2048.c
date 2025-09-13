/*
2048
    -2048.c is a cross platform single
    file game of 2048. All you need to
    do is compile and run it. type WASD
    keys and press ENTER to move the
    tiles. Be careful inputs are buffered,
    so you can play more than one move
    in one enter command. Have Fun!
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define FOR(v, r) for (int v = 0; v < r; v++)
#define FORI(v, r) for (int v = r - 1; v > -1; v--)
#define RANDOM(l, u) ((rand() % (u - l + 1)) + l)
#define PRINT(s, ...) printf(s, ##__VA_ARGS__);
#define ESCAPE "\x1b["
#define NEWLINE "\n"

#define CR_HIDE ESCAPE "?25l"
#define CR_SHOW ESCAPE "?25h"

#define CL_SCREEN ESCAPE "2J"
#define RESET_ALL ESCAPE "0m"

#define ST_BOLD ESCAPE "1m"
#define ST_DIM ESCAPE "2m"
#define ST_UNDERLINE ESCAPE "4m"
#define ST_BLINK ESCAPE "5m"
#define ST_REVERSE ESCAPE "7m"

#define FG_BLACK ESCAPE "30m"
#define FG_RED ESCAPE "31m"
#define FG_GREEN ESCAPE "32m"
#define FG_YELLOW ESCAPE "33m"
#define FG_BLUE ESCAPE "34m"
#define FG_MAGENTA ESCAPE "35m"
#define FG_CYAN ESCAPE "36m"
#define FG_WHITE ESCAPE "37m"

#define BG_BLACK ESCAPE "40m"
#define BG_RED ESCAPE "41m"
#define BG_GREEN ESCAPE "42m"
#define BG_YELLOW ESCAPE "43m"
#define BG_BLUE ESCAPE "44m"
#define BG_MAGENTA ESCAPE "45m"
#define BG_CYAN ESCAPE "46m"
#define BG_WHITE ESCAPE "47m"

#define KEY_UP 'w'
#define KEY_DOWN 's'
#define KEY_LEFT 'a'
#define KEY_RIGHT 'd'
#define KEY_EXIT 'q'

#define VERTICAL_BORDER FG_WHITE BG_BLACK "|" RESET_ALL
#define HORIZONTAL_BORDER FG_WHITE BG_BLACK "-----" RESET_ALL

#define SLOT_EMPTY FG_BLACK BG_BLACK "     " RESET_ALL
#define SLOT_2 FG_BLACK BG_WHITE "  2  " RESET_ALL
#define SLOT_4 FG_WHITE BG_BLUE "  4  " RESET_ALL
#define SLOT_8 FG_WHITE BG_CYAN "  8  " RESET_ALL
#define SLOT_16 FG_WHITE BG_GREEN "  16 " RESET_ALL
#define SLOT_32 FG_WHITE BG_YELLOW "  32 " RESET_ALL
#define SLOT_64 FG_WHITE BG_MAGENTA "  64 " RESET_ALL
#define SLOT_128 FG_WHITE BG_RED " 128 " RESET_ALL
#define SLOT_256 FG_BLACK BG_WHITE " 256 " RESET_ALL
#define SLOT_512 FG_BLACK BG_WHITE " 512 " RESET_ALL
#define SLOT_1024 FG_BLACK BG_WHITE " 1024" RESET_ALL
#define SLOT_2048 FG_BLACK BG_WHITE " 2048" RESET_ALL

unsigned short SLOTS[4][4], RAND_LINE, RAND_ROW = {0};
char *SLOT_IMAGES[2049] = {0};
char CHAR = KEY_DOWN;

int main()
{
    srand(time(NULL));
    SLOT_IMAGES[0] = SLOT_EMPTY;
    SLOT_IMAGES[2] = SLOT_2;
    SLOT_IMAGES[4] = SLOT_4;
    SLOT_IMAGES[8] = SLOT_8;
    SLOT_IMAGES[16] = SLOT_16;
    SLOT_IMAGES[32] = SLOT_32;
    SLOT_IMAGES[64] = SLOT_64;
    SLOT_IMAGES[128] = SLOT_128;
    SLOT_IMAGES[256] = SLOT_256;
    SLOT_IMAGES[512] = SLOT_512;
    SLOT_IMAGES[1024] = SLOT_1024;
    SLOT_IMAGES[2048] = SLOT_2048;

    SLOTS[RANDOM(0, 3)][RANDOM(0, 3)] = 2;

    do
    {
        // move tiles
        switch (CHAR)
        {
        case KEY_DOWN:
            FORI(l, 4)
            {
                FOR(r, 4)
                {
                    if (!SLOTS[l][r])
                        continue;
                    int lcp = l;
                    while (++lcp != 4)
                    {
                        if (!SLOTS[lcp][r])
                        {
                            SLOTS[lcp][r] = SLOTS[lcp - 1][r];
                            SLOTS[lcp - 1][r] = 0;
                        }
                        else if (SLOTS[lcp][r] == SLOTS[lcp - 1][r])
                        {
                            SLOTS[lcp][r] = SLOTS[lcp][r] + SLOTS[lcp - 1][r];
                            SLOTS[lcp - 1][r] = 0;
                        }
                    }
                }
            }
            break;
        case KEY_UP:
            FOR(l, 4)
            {
                FOR(r, 4)
                {
                    if (!SLOTS[l][r])
                        continue;
                    int lcp = l;
                    while (--lcp != -1)
                    {
                        if (!SLOTS[lcp][r])
                        {
                            SLOTS[lcp][r] = SLOTS[lcp + 1][r];
                            SLOTS[lcp + 1][r] = 0;
                        }
                        else if (SLOTS[lcp][r] == SLOTS[lcp + 1][r])
                        {
                            SLOTS[lcp][r] = SLOTS[lcp][r] + SLOTS[lcp + 1][r];
                            SLOTS[lcp + 1][r] = 0;
                        }
                    }
                }
            }
            break;
        case KEY_RIGHT:
            FOR(l, 4)
            {
                FORI(r, 4)
                {
                    if (!SLOTS[l][r])
                        continue;
                    int rcp = r;
                    while (++rcp != 4)
                    {
                        if (!SLOTS[l][rcp])
                        {
                            SLOTS[l][rcp] = SLOTS[l][rcp - 1];
                            SLOTS[l][rcp - 1] = 0;
                        }
                        else if (SLOTS[l][rcp] == SLOTS[l][rcp - 1])
                        {
                            SLOTS[l][rcp] = SLOTS[l][rcp] + SLOTS[l][rcp - 1];
                            SLOTS[l][rcp - 1] = 0;
                        }
                    }
                }
            }
            break;
        case KEY_LEFT:
            FOR(l, 4)
            {
                FOR(r, 4)
                {
                    if (!SLOTS[l][r])
                        continue;
                    int rcp = r;
                    while (--rcp != -1)
                    {
                        if (!SLOTS[l][rcp])
                        {
                            SLOTS[l][rcp] = SLOTS[l][rcp + 1];
                            SLOTS[l][rcp + 1] = 0;
                        }
                        else if (SLOTS[l][rcp] == SLOTS[l][rcp + 1])
                        {
                            SLOTS[l][rcp] = SLOTS[l][rcp] + SLOTS[l][rcp + 1];
                            SLOTS[l][rcp + 1] = 0;
                        }
                    }
                }
            }
            break;
        default:
            continue;
        }

        // create new tile
        do
        {
            RAND_LINE = RANDOM(0, 3);
            RAND_ROW = RANDOM(0, 3);
        } while (SLOTS[RAND_LINE][RAND_ROW] != 0);

        SLOTS[RAND_LINE][RAND_ROW] = 2;

        // render
        PRINT(CL_SCREEN RESET_ALL CR_HIDE);
        PRINT(NEWLINE);
        FOR(i, 4)
        {
            PRINT(VERTICAL_BORDER HORIZONTAL_BORDER);
        }
        PRINT(VERTICAL_BORDER);

        FOR(l, 4)
        {
            PRINT(NEWLINE);
            FOR(r, 4)
            {
                PRINT(VERTICAL_BORDER);
                PRINT(SLOT_IMAGES[SLOTS[l][r]]);
            }
            PRINT(VERTICAL_BORDER);

            PRINT(NEWLINE);
            FOR(i, 4)
            {
                PRINT(VERTICAL_BORDER HORIZONTAL_BORDER);
            }
            PRINT(VERTICAL_BORDER);
        }

        PRINT(NEWLINE);
    } while ((CHAR = getchar()) != KEY_EXIT);
    return 0;
}