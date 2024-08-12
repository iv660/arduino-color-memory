#if !defined(STORAGE_H)
#define STORAGE_H

#include "PersistentData.h"

class Storage
{
    private:
        PersistentData data;
        const uint8_t eepromKey = 32;
    public:
        Storage();
        PersistentData getData();
        Storage* setHighScore(int highScore);
        void store();
        void reset();
};

#endif // STORAGE_H
