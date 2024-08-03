#if !defined(GAMESTATE_H)
#define GAMESTATE_H

#include "LevelOptions.h"

struct GameState
{
    LevelOptions levelOptions;
    int roundsLeft = 5;
    int level = 1;
    int lives = 1;
};


#endif // GAMESTATE_H
