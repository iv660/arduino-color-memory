#include "StageInterface.h"
#include "BaseStage.h"
#include "StartupStage.h"
#include "PlaySequenceStage.h"
#include "StagesLocator.h"

void StartupStage::waitForAnyKey() {
  const int buttonPin = 2;
  
  unsigned long lastDebounceTime = 0;  // the last time the output pin was toggled
  unsigned long debounceDelay = 50;    // the debounce time; increase if the output flickers
  int buttonState;
  int lastButtonState = LOW;  // the previous reading from the input pin
  bool buttonIsDown = false;
  
  int reading;
  
  while (!buttonIsDown) {
    reading = digitalRead(buttonPin);

    if (reading != lastButtonState) {
      lastDebounceTime = millis();
    }

    if ((millis() - lastDebounceTime) > debounceDelay) {
      if (reading != buttonState) {
        buttonState = reading;

        // only toggle the LED if the new button state is HIGH
        if (buttonState == HIGH) {
          buttonIsDown = true;
        } else {
          buttonIsDown = false;
        }
      }
    }

    lastButtonState = reading;
  }
}

StageInterface* StartupStage::run() {
  waitForAnyKey();

  return mStagesLocator->playSequenceStage;
}

const StagesLocator* stagesLocator = new StagesLocator();
const StageInterface* currentStage = stagesLocator->startupStage;

// the setup function runs once when you press reset or power the board
void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(2, INPUT);
}

// the loop function runs over and over again forever
void loop() {
  if (currentStage) {
    currentStage = currentStage->run();
  }
}
