#include <Arduino.h>
#include "StageInterface.h"
#include "StagesLocator.h"
#include "ServiceLocator.h"
#include "Key.h"
#include "storage/Storage.h"
#include "const.h"

const StagesLocator* stagesLocator = new StagesLocator;
StageInterface* currentStage = stagesLocator->startupStage;

// the setup function runs once when you press reset or power the board
void setup() 
{
    // Serial.begin(9600);
    // while(!Serial);

    if (digitalRead(KEY4) && digitalRead(KEY5)) {
        Storage().reset();
    }

    randomSeed(analogRead(A5) * 10);
}

// the loop function runs over and over again forever
void loop() 
{
    if (currentStage) {
        currentStage = currentStage->run();
    }
}
