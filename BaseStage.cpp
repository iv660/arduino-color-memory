#include "BaseStage.h"
#include "StagesLocator.h"

BaseStage::BaseStage(
    StagesLocator* stagesLocator, ServiceLocator* serviceLocator): 
    serviceLocator(serviceLocator), stagesLocator(stagesLocator) {}