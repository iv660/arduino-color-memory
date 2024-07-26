#if !defined(KEYPAD_H)
#define KEYPAD_H

#include "const.h"
#include "Key.h"

class Keypad 
{
    Key key1 = Key(KEY1);
    Key key2 = Key(KEY2);
    Key key3 = Key(KEY3);
    Key key4 = Key(KEY4);
    Key key5 = Key(KEY5);
    
    public:
        int getInput();
};

#endif // KEYPAD_H
