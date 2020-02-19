class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        int ans = 0;
        int pos = 1;
        if(nums.size() == 0 || nums[0] != 1) ans++,pos = 0;
        long long nowCover = 1;
        while(nowCover < n){
            //当前的可以覆盖的和的范围是[1,n)时，添加一个数m则覆盖范围是[1,n)并[m,m+n)
            if(pos < nums.size()){
                if(nums[pos] <= nowCover+1){ 
                    nowCover = nowCover+1+nums[pos]-1;//这个时候这个时候的覆盖的范围是[1,nowcover+1)并[nums[pos],nowcover+1+nums[pos])=[1,nowCover+1+nums[pos]-1)所以
                    //更新能扩大到的最大范围是 nowCover+1+nums[pos]-1
                    pos++;
                }
                else{
                    ans++;
                    nowCover = 2*(nowCover+1)-1;//这个时候出现了断裂，因为这个时候的覆盖的范围是[1,nowcover+1)并[nums[pos],nowcover+1+nums[pos]).为了保证连续，能选择的加入的
                    //最大的数就是当前未被覆盖的和nowCover+1
                }
            }
            else{
                ans++;
                nowCover = 2*(nowCover+1)-1;
            }
        }
        return ans;
    }
};