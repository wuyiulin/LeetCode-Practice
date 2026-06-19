class Solution {
public:
    double angleClock(int hour, int minutes) 
    {
        double res = 400;
        double h = 30 * (hour % 12) + (minutes*1.0 / 60) * 30;
        double m = minutes * 6;
        res = abs(h - m);
        res = min(res, 360 - res);

        return res;
    }
};