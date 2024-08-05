#if !defined(DASHBOARDDISPLAY_H)
#define DASHBOARDDISPLAY_H)

#include <GyverSegment.h>

class DashboardDisplay
{
    private:
        uint8_t dio;
        uint8_t clk;

        Disp1637Colon display;

        void showReadout(char* caption, int value);
        void showInstantReadout(char* caption, int value);
        void showReadoutTransition(char* caption, int fromValue, int toValue);
    public:
       DashboardDisplay(uint8_t dio, uint8_t clk) : display(dio, clk), dio(dio), clk(clk) {};
       DashboardDisplay* showLevel(int level);
       DashboardDisplay* showLevelTransition(int from, int to);
       DashboardDisplay* showHighScore(int score);
       DashboardDisplay* showHighScoreTransition(int from, int to);
       DashboardDisplay* showMovesLeft(int movesLeft);
       DashboardDisplay* showRoundsLeft(int roundsLeft);
       DashboardDisplay* showLivesLeftTransition(int from, int to);
       DashboardDisplay* clear();
};

#endif // DASHBOARDDISPLAY_H)
