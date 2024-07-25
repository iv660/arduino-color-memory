#ifndef STAGEINTERFACE_H
#define STAGEINTERFACE_H

// #include "StagesLocator.h";
class StagesLocator;

/**
 * Game stage.
 */
class StageInterface 
{
  protected:
    StagesLocator* stagesLocator;
  public:
    virtual StageInterface* run() = 0;
};

#endif