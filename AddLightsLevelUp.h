#if !defined(ADDCLIGHTSLEVELUP_H)
#define ADDCLIGHTSLEVELUP_H

#include "GameState.h"
#include "LevelUpInterface.h"

class AddLightsLevelUp : public LevelUpInterface {
public:
    GameState updateState(GameState gameState) override;
    bool canHandle(GameState gameState) override;
};

#endif // ADDCLIGHTSLEVELUP_H