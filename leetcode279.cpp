class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n+1,0x3f3f3f3f);
        for(int i = 1 ; i <= n ; i++){
            if(sqrt(i) == int(sqrt(i)))
                dp[i] = 1;
            else{
                for(int j = 1 ; j*j <= i-j*j ; j++){
                    dp[i] = min(dp[i],dp[j*j]+dp[i-j*j]);
                }
            }
            
        }
        return dp[n];
    }
};