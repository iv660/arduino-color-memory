#include "const.h"
#include "ServiceLocator.h"
#include "DashboardDisplay.h"

DashboardDisplay* ServiceLocator::getDashboard()
{ 
    if (!dashboard) {
        dashboard = new DashboardDisplay(
            DASHBOARD_DIO, DASHBOARD_CLK);
    }


    return dashboard; 
}