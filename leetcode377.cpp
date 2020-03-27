class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        unordered_map<int,long>dp;
        sort(nums.begin(),nums.end());
        dp[0] = 1;
        for(int i = 1 ; i <= target ; i++){
            for(int j = 0 ; j < nums.size() ; j++){
                if(nums[j] > i) break;
                if(dp[i-nums[j]] != 0){
                    dp[i] += dp[i-nums[j]];
                    int t = INT_MAX;
                    dp[i] = t<=dp[i]?t:dp[i];
                }
                    
                
            }
            //cout <<"i "<<i << " "<< dp[i] << endl;
        }
        return dp[target];
    }
};