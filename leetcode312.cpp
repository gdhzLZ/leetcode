class Solution {
public:
    int maxCoins(vector<int>& nums) {
        vector<vector<int>> dp(nums.size(),vector<int>(nums.size(),0));
        if(nums.size() == 0)
            return 0;
        int ans = 0;
        for(int length = 0 ; length < nums.size() ; length++){
            for(int start = 0 ; start+length < nums.size(); start++){
                int end = start+length;
                for(int i = start; i <= end ; i++){
                    int left = 1;
                    if(start-1>=0) left = nums[start-1];
                    int right = 1;
                    if(end+1 < nums.size()) right = nums[end+1];
                    int dp1 = 0;
                    if(i-1>=start)dp1 = dp[start][i-1];
                    int dp2 = 0;
                    if(i+1 <= end) dp2 = dp[i+1][end];
                    int temp = dp1+dp2+nums[i]*left*right;
                    dp[start][end] = max(dp[start][end],temp);
                    ans = max(ans,dp[start][end]);
                }
            }
        }
        return ans;
    }
};