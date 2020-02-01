class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        for(int i = 0 ; i < nums.size() ; i++){
            //cout << nums[i] << " " << i << endl;
            if(nums[i] != i+1){
                int t = nums[i];
                if (t <= nums.size()- 1&& t>0 &&nums[t-1] != t){
                    swap(nums[t-1],nums[i]);
                    i--;
                }
            }
        }
        for(int i = 0 ; i < nums.size() ; i++){
            if(nums[i] != i+1)
                return i+1;
        }
        return nums.size()+1;
    }
};