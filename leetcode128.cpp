class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> dp;
        int ret = 0;
        for(auto &x : nums) {
            if(!dp[x]) dp[x - dp[x - 1]] = dp[x + dp[x + 1]] = dp[x] = dp[x - 1] + dp[x + 1] + 1;
            ret = max(ret, dp[x]);
        }
        return ret;
    }
};
