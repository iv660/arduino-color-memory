#if !defined(SERVICELOCATORS_H)
#define SERVICELOCATORS_H

#include "const.h"

#include "DashboardDisplay.h"

class ServiceLocator
{
    private:
        DashboardDisplay* dashboard = nullptr;
    public:
        DashboardDisplay* getDashboard();
};


#endif // SERVICELOCATORS_H
