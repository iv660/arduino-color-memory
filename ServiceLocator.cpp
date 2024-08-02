#include "const.h"
#include "ServiceLocator.h"
#include "DashboardDisplay.h"

DashboardDisplay* ServiceLocator::getDashboard()
{ 
    Serial.println("In getDashboard()");
    if (!dashboard) {
        Serial.println("Dashboard initialized");
        dashboard = new DashboardDisplay(
            DASHBOARD_DIO, DASHBOARD_CLK);
    }


    return dashboard; 
}