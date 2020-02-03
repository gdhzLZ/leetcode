class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans;
        if(nums.size() == 0) {
            ans.push_back(-1);
            ans.push_back(-1);
            return ans;
        }
        int left = 0,right = nums.size()-1;
        while(left < right){
            int mid = (left+right)/2;
            if(nums[mid] < target)left = mid+1;
            else right = mid;
        }
        if(nums[left] == target) ans.push_back(left);
        else{
        ans.push_back(-1);
        }
    
        left = 0,right = nums.size()-1;
         while(left < right){
            int mid = (left+right)*1.0/2+0.5;
            if(nums[mid] <= target)left = mid;
            else right = mid-1;
            //cout <<left << " " <<right << endl;
         }
        if(nums[left] == target) ans.push_back(left);
        else{
        ans.push_back(-1);
        }
        return ans;
        
        
    }
};