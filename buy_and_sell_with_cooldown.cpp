class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        if(n<=1) return 0;
        
        int dp[n][2];
        dp[0][0]=-prices[0];dp[0][1]=0;
        dp[1][0]=-1*min(prices[0],prices[1]);dp[1][1]=max(0,prices[1]-prices[0]);
        
        for(int i=2;i<n;i++){
            dp[i][0]=max(dp[i-1][0],-prices[i]+dp[i-2][1]);
            dp[i][1]=max(dp[i-1][1],prices[i]+dp[i-1][0]);
        }
        
        return dp[n-1][1];
    }
};