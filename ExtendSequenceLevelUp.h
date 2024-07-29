#if !defined(EXPANDSEQUENCELEVELUP_H)
#define EXPANDSEQUENCELEVELUP_H

#include "GameState.h"
#include "LevelUpInterface.h"

class ExtendSequenceLevelUp : public LevelUpInterface {
    private:
        void playLevelUpAnimation();
    public:
        GameState updateState(GameState gameState) override;
};

#endif // EXPANDSEQUENCELEVELUP_H