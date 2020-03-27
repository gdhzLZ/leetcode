class Solution {
public:
    int Max(vector<int> nums){
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
    int rob(vector<int>& nums) {
        if(nums.size() == 0)
            return 0;
        if(nums.size() == 1)
            return nums[0];
        int t = nums[nums.size()-1];
        nums.pop_back();
        int ans1 = Max(nums);
        nums.push_back(t);
        nums.erase(nums.begin());
        int ans2 = Max(nums);
        return max(ans1,ans2);
    }
};