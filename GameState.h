#if !defined(GAMESTATE_H)
#define GAMESTATE_H

#include "LevelOptions.h"

struct GameState
{
    LevelOptions levelOptions;
    int roundsLeft = 5;
};


#endif // GAMESTATE_H
