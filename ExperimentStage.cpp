#include "const.h"
#include "ExperimentStage.h"
#include "Key.h"
#include "SignalsDisplay.h"
#include "StageInterface.h"

StageInterface *ExperimentStage::run()
{
    SignalsDisplay signals;

    signals.all.blink(50, 2);

    return this;
}