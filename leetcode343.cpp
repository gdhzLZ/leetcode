class Solution {
public:
    int integerBreak(int n) {
        int dp[59] = {0};
        dp[0] = 0,dp[1] = 1,dp[2] = 1;
        for(int i = 3 ; i <= n ; i++){
            for(int j = 1 ; j < i ; j++){
                dp[i] = max(dp[i],max(i-j,dp[i-j])*j);
            }
        }
        //cout << dp[3] <<" "<< dp[4] << " " <<dp[5] << " " <<dp[6] <<endl;
        return dp[n];
    }
};