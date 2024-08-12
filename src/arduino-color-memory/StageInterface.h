#ifndef STAGEINTERFACE_H
#define STAGEINTERFACE_H

/**
 * Game stage.
 */
class StageInterface 
{
  public:
    virtual StageInterface* run() = 0;
};

#endif