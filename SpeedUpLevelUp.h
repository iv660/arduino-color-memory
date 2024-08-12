#if !defined(SPEEDUPLEVELUP_H)
#define SPEEDUPLEVELUP_H

#include "LevelUpInterface.h"

class SpeedUpLevelUp: public LevelUpInterface
{
    private:
    public:
        GameState updateState(GameState gameState) override;
        bool canHandle(GameState gameState) override;
};

#endif // SPEEDUPLEVELUP_H
