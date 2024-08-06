#include <EEPROM.h>
#include "Storage.h"

Storage::Storage()
{
    data = PersistentData();

    int keyAddress = EEPROM.length() - 1;

    uint8_t storedEepromKey = EEPROM.read(keyAddress);

    if (storedEepromKey != eepromKey) {
        EEPROM.put(1, data);
        EEPROM.put(keyAddress, eepromKey);
    }

    EEPROM.get(1, data);
}

PersistentData Storage::getData()
{
    return data;
}

Storage* Storage::setHighScore(int highScore)
{
    data.highScore = highScore;

    return this;
}

void Storage::store()
{
    EEPROM.put(1, data);
}
