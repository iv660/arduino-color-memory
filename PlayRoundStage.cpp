#include <Arduino.h>
#include "PlayRoundStage.h"
#include "StageInterface.h"
#include "StagesLocator.h"
#include "Light.h"
#include "SignalsDisplay.h"

int PlayRoundStage::getSequenceLenght()
{
    return gameState.levelOptions
        .sequenceLength;
}

void PlayRoundStage::waitFor(int pauseMillis)
{
    delay(pauseMillis);
}

StageInterface* PlayRoundStage::run() 
{
    playSequence();
    playReadyForInputAnimation();
    bool inputIsCorrect = checkInputAgainstSequence();
    
    return getNextStage(inputIsCorrect);
}

PlayRoundStage * PlayRoundStage::setGameState(GameState gameState)
{
    this->gameState = gameState;

    return this;
}

void PlayRoundStage::playSequence()
{
    sequence.generate(getSequenceLenght(), minValue, 
        gameState.levelOptions.maxValue);
    while (sequence.hasNext()) {
        sequenceDisplay.show(sequence.next(), duration);
        waitFor(pause);
    }
}

void PlayRoundStage::playReadyForInputAnimation()
{
    SignalsDisplay display;
    display.all.blink(100, 1);
}

bool PlayRoundStage::checkInputAgainstSequence()
{
    for (int index = 1; index <= getSequenceLenght(); index++) {
        int key = keypad.getInput();
        if (false == sequence.checkInput(index, key)) {
            return false;
        }
    }
    
    return true;
}

StageInterface* PlayRoundStage::getNextStage(bool inputIsCorrect)
{
    if (inputIsCorrect) {
        return stagesLocator->roundWonStage
            ->setGameState(gameState);
    }
    return stagesLocator->roundLostStage
        ->setGameState(gameState);
}
