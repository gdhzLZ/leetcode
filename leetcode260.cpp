class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        vector<int> ans;
        int temp = 0;
        for(int i = 0  ; i < nums.size();i++)
            temp = temp^nums[i];
        int tempLowbit = temp&(-temp);
        int a = 0,b = 0;
       
        for(int i = 0 ; i < nums.size() ;i++){
            if((nums[i]&tempLowbit) == tempLowbit) a = a^nums[i];
            else b = b^nums[i];
        }
        ans.push_back(a);
        ans.push_back(b);
        return ans;

    }
};