#include "gcl.h"

extern int  GM_GameStatus_800AB3CC;

int sub_8003F50C(void)
{
    GM_GameStatus_800AB3CC &= ~GAME_FLAG_BIT_16;
    return GM_GameStatus_800AB3CC;
}
