#ifndef LEVELUPINTERFACE_H
#define LEVELUPINTERFACE_H

#include "GameState.h"

class LevelUpInterface {
    public:
        virtual GameState updateState(GameState gameState) = 0;
        virtual bool canHandle(GameState gameState) = 0;
};

#endif // LEVELUPINTERFACE_H