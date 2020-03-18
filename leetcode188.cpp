class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        //dp[i][0] notholdMax after i times trades,dp[i][1]holdMax after i times trades
        int t = prices.size();
        cout << t <<endl;
        vector<vector<int>>dp(min(t+1,k+1),vector<int>(2,-0x3f3f3f));
        cout << t <<endl;
        if(prices.size() == 0 ) return 0;
        dp[0][0] = 0;
        dp[0][1] = -prices[0];
        int ans = -0x3f3f3f;
        for(int i = 1 ; i < prices.size() ; i++){
            int tradeMax = min(i+1,k);
            for(int j = tradeMax ; j >= 1 ; j--){
                dp[j][1] = max(dp[j][1],dp[j][0]-prices[i]);
                dp[j][0] = max(dp[j][0],dp[j-1][1]+prices[i]);
                
            }
            dp[0][0] = 0;
            dp[0][1] = max(dp[0][1],-prices[i]);
           // for(int i = 0 ; i <= k ; i++)
             //   cout << dp[i][0] << " " << dp[i][1] << " ";
            //cout << endl;
        }
        for(int i = 0 ; i <dp.size() ; i++)
            ans = max(ans,dp[i][0]);
        return ans;
    }
};