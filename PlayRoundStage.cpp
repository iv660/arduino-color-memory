#include <Arduino.h>
#include "PlayRoundStage.h"
#include "StageInterface.h"
#include "StagesLocator.h"
#include "Light.h"
#include "SignalsDisplay.h"

int PlayRoundStage::getSequenceLenght()
{
    Serial.print("Sequence length: ");
    Serial.println(gameState.levelOptions.sequenceLength);
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
    Serial.println("checkInputAgainstSequence() >>>");
    for (int index = 1; index <= getSequenceLenght(); index++) {
        Serial.println("Inside loop >>>");
        int key = keypad.getInput();
        Serial.print("Got key input: ");
        Serial.println(key);
        if (false == sequence.checkInput(index, key)) {
            Serial.println("Input is wrong!");
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
