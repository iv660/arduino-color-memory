#include <WString.h>
#include <GyverSegment.h>
#include "DashboardDisplay.h"

void DashboardDisplay::showReadout(char * caption, int value)
{
    SegAnimation<3> animation(&display, 1);
    animation.setEffect(SegEffect::TwistFill, 500);

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

void DashboardDisplay::showInstantReadout(char * caption, int value)
{
    display.setCursor(0);
    display.clear();
    display.print(caption);
    display.setCursorEnd(sseg::intLen(value) - 1);
    display.print(value);
    display.update();
}

void DashboardDisplay::showReadoutTransition(char * caption, 
    int fromValue, int toValue)
{
    SegAnimation<3> animation(&display, 1);
    animation.setEffect(SegEffect::TwistFill, 500);

    showInstantReadout(caption, fromValue);
    display.delay(500);

    animation.start();
    animation.setCursorEnd(sseg::intLen(toValue) - 1);
    animation.print(toValue);
    animation.waitEnd();
}

DashboardDisplay *DashboardDisplay::showLevel(int level)
{
    showReadout("Y", level);
    return this;
}

DashboardDisplay * DashboardDisplay::showLevelTransition(int from, int to)
{
    showReadoutTransition("Y", from, to);
    return this;
}

DashboardDisplay *DashboardDisplay::showHighScore(int score)
{
    showReadout("P", score);
    return this;
}

DashboardDisplay * DashboardDisplay::showMovesLeft(int movesLeft)
{
    showInstantReadout("O", movesLeft);
    return this;
}

DashboardDisplay *DashboardDisplay::showRoundsLeft(int roundsLeft)
{
    showInstantReadout("^", roundsLeft);
    return this;
}

DashboardDisplay* DashboardDisplay::showLivesLeftTransition(
    int from, int to)
{   
    showReadoutTransition("N", from, to);
    return this;
}

DashboardDisplay *DashboardDisplay::clear()
{
    display.clear();
    display.update();

    return this;
}
