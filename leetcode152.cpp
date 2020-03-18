class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if(nums.size() ==0)    return 0;
        int N = 0x3f3f3f3f;
        int  lastPositive = -N;
        int  lastNegative = N;
        int  ans = -N; 
        for(int i = 0 ; i < nums.size() ; i++ ){
            if(nums[i] > 0){
                if(lastPositive != -N ){
                    lastPositive = max (nums[i],lastPositive * nums[i]);
                }
                else{
                    lastPositive = nums[i];
                }
                if(lastNegative != N)
                    lastNegative *= nums[i];
                else lastNegative =N;
                ans = max(ans,lastPositive);
            }
            else if(nums[i] < 0){
                int temp = lastNegative;
                if(lastPositive != -N){
                    lastNegative = min(nums[i],lastPositive*nums[i]);
                }
                else{
                    lastNegative = nums[i];
                }
                if(temp != N)
                    lastPositive = temp*nums[i];
                else lastPositive = -N;
                ans = max(ans,max(lastPositive,lastNegative));

            }
            else{
                lastPositive = 0,lastNegative = 0;
                ans = max(ans,0);
            }
            //cout << lastPositive << " "<<lastNegative<<endl;
        }
        return ans;
    }
};