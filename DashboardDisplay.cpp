#include <WString.h>
#include <GyverSegment.h>
#include "DashboardDisplay.h"

void DashboardDisplay::showReadout(char * caption, int value)
{
    Disp1637Colon display(dio, clk, false);
    SegAnimation<3> animation(&display, 1);
    animation.setEffect(SegEffect::TwistFill, 500);

    clear();

    display.setCursor(0);
    display.clear();

    display.print(caption);
    display.update();
    display.delay(500);

    animation.start();
    animation.setCursorEnd(sseg::intLen(value) - 1);
    animation.print(value);
    animation.waitEnd();
}

DashboardDisplay::DashboardDisplay(uint8_t dio, uint8_t clk)
{
    this->dio = dio;
    this->clk = clk;
}

DashboardDisplay *DashboardDisplay::showLevel(int level)
{
    showReadout("Y", level);
    return this;
}

DashboardDisplay *DashboardDisplay::showHighScore(int score)
{
    showReadout("P", score);
    return this;
}

DashboardDisplay *DashboardDisplay::clear()
{
    Disp1637Colon(dio, clk, false).clear();

    return this;
}
