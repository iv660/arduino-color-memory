#if !defined(EXPANDSEQUENCELEVELUP_H)
#define EXPANDSEQUENCELEVELUP_H

#include "GameState.h"

class ExpandSequenceLevelUp
{
    private:
        void playLevelUpAnimation();
    public:
        GameState updateState(GameState gameState);
};

#endif // EXPANDSEQUENCELEVELUP_H
