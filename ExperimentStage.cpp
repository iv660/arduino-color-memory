#include "const.h"
#include "ExperimentStage.h"
#include "Key.h"
#include "SignalsDisplay.h"
#include "StageInterface.h"

StageInterface *ExperimentStage::run()
{
    Key key(KEY1);
    SignalsDisplay signals;

    while (key.isUp());
    signals.red.on();
    while (key.isDown());
    signals.red.off();

    signals.all.blink(50, 2);

    return this;
}