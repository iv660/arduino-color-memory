#if !defined(KEYPAD_H)
#define KEYPAD_H

#include "const.h"
#include "Key.h"

class Keypad 
{
    private: 
        Key key1 = Key(KEY1);
        Key key2 = Key(KEY2);
        Key key3 = Key(KEY3);
        Key key4 = Key(KEY4);
        Key key5 = Key(KEY5);

        int numberOfKeys = 5;

        Key* keys[5] = {&key1, &key2, &key3, &key4, &key5};
    
    public:
        int getInput();
};

#endif // KEYPAD_H
