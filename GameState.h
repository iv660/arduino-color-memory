#if !defined(GAMESTATE_H)
#define GAMESTATE_H

#include "LevelOptions.h"

struct GameState
{
    LevelOptions levelOptions;
    int roundsLeft = LevelOptions().roundsToPlay;
    int level = 1;
    int lives = 3;
    int highScore = 0;
};


#endif // GAMESTATE_H
