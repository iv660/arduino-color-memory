#include "Keypad.h"

int Keypad::getInput()
{
    while (true) {
        for (int keyIndex = 0; keyIndex <= numberOfKeys - 1; keyIndex++) {
            if (keys[keyIndex]->isDown()) {
                while(keys[keyIndex]->isDown());
                return keyIndex + 1;
            }
        }
    }
}