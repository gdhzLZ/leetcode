class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for(int i = 31 ; i >= 0 ; i--){
            int num = 0;
            for(int j = 0 ; j < nums.size() ; j++){
                if((nums[j] >> i)&1 == 1) num++;
            }
            ans = ans << 1;
            ans = ans | (num%3);
        }
        return ans;
    }
};