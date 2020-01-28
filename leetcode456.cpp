/*
还是太菜了，试了很多想法要么是超时，要么是错误。想的麻烦了。
最朴素的dp就完事了。n2复杂度。对于每一次内循环，起点是不变的，
只需要更改区间[first,second]的j就可以，改变之前先检查一下，当前的数在
不在区间里。如果在返回true，不再就看是否会让这个上升区间拉长，
可以的话就把second改成当前的nums[j]。初始的first,second可以设置成nums[i]
显然这个做法不是最好的。但思路很清晰。
*/

class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        set<int>visited2;
        vector<pair<int,int>> visited;
        if(nums.size() < 3) return false;
        for(int i = 0 ; i < nums.size(); i++){
            pair<int,int>memory;
            memory.first = memory.second = nums[i];
            for(int j = i+1 ; j < nums.size() ; j++){
                if(nums[j] > memory.first && nums[j] < memory.second){
                    return true;
                }
                else if(nums[j] > memory.second)
                    memory.second = nums[j];
            }
        }
        return false;
    }
};