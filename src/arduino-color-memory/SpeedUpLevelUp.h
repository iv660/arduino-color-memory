#if !defined(SPEEDUPLEVELUP_H)
#define SPEEDUPLEVELUP_H

#include "LevelUpInterface.h"
#include "GameState.h"

class SpeedUpLevelUp: public LevelUpInterface
{
    private:
        GameState speedUp(GameState gameState);
        GameState resetSequenceLength(GameState gameState);
    public:
        GameState updateState(GameState gameState) override;
        bool canHandle(GameState gameState) override;
};

#endif // SPEEDUPLEVELUP_H
