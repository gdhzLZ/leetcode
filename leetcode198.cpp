class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 0)
            return 0;
        int lastNotStole = 0;
        int lastStole = nums[0];
        for(int i = 1 ; i < nums.size() ; i++){
            int temp = lastStole;
            lastStole = lastNotStole+nums[i];
            lastNotStole = max(lastNotStole,temp);
        }
        return max(lastStole,lastNotStole);
    }
};