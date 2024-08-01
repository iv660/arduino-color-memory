#if !defined(DASHBOARDDISPLAY_H)
#define DASHBOARDDISPLAY_H)

class DashboardDisplay
{
    private:
        uint8_t dio;
        uint8_t clk;

        void showReadout(char* caption, int value);
        void showInstantReadout(char* caption, int value);
    public:
       DashboardDisplay(uint8_t dio, uint8_t clk);
       DashboardDisplay* showLevel(int level);
       DashboardDisplay* showHighScore(int score);
       DashboardDisplay* showMovesLeft(int movesLeft);
       DashboardDisplay* clear();
};

#endif // DASHBOARDDISPLAY_H)
