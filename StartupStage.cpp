#include <Arduino.h>
#include "StartupStage.h"
#include "StagesLocator.h"
#include "const.h"
#include "Key.h"
#include "Light.h"

void StartupStage::waitForAnyKey() {
  pinMode(KEY1, INPUT);
  while (digitalRead(KEY1) == LOW) {

  }

  return;

  // Key key = Key(KEY1);

  // while (key.isUp()) {
  //   // Do nothing
  // }

  // Light(PIN3).blink(100, 3);

  // Serial.println(">>> in");

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
  // Serial.println("out >>>");
  // Light(PIN5).blink(100, 5);
}

StageInterface* StartupStage::run() {
  Light* l = new Light(9);
  l->blink(300, 9);
  delete l;

  waitForAnyKey();

  return stagesLocator->playRoundStage;
}

