#if !defined(ADDROUNDSLEVELUP_H)
#define ADDROUNDSLEVELUP_H

#include "LevelUpInterface.h"

class AddRoundsLevelUp: public LevelUpInterface
{
    private:
    public:
        GameState updateState(GameState gameState);
        bool canHandle(GameState gameState);
};

#endif // ADDROUNDSLEVELUP_H
