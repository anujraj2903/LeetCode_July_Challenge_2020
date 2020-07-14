class Solution {
public:
    double angleClock(int hour, int minutes) {
        double h=30*hour+((double)minutes)/2;
        int m=6*minutes;
        double x=abs(h-m);
        
        return min(x,360-x);
        
        
    }
};