class Solution {
public:
    
    double bin(double a,long long b){
        double res=1;
        while(b){
            if(b&1) res=res*a;
            a=(a*a);
            b/=2;
        }
        
        return res;
    }
    double myPow(double x, int n) {
        long long b=n;
        if(b<0) return 1/bin(x,-1*b);
        return bin(x,b);
    }
};