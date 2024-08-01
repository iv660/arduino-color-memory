#include "Keypad.h"

int Keypad::getInput()
{
    while (true) {
        for (int keyIndex = 0; keyIndex <= numberOfKeys - 1; keyIndex++) {
            if (keys[keyIndex]->isDown()) {
                Serial.print("Key: ");
                Serial.println(keyIndex + 1);
                while(keys[keyIndex]->isDown());
                return keyIndex + 1;
            }
        }
    }
}