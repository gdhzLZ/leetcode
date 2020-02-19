class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        int pos = 0;
        while(pos+1 < nums.size() && nums[pos+1]-nums[pos] == 0){
            pos++;
        }
        if(pos >= nums.size()-1) return 1;//如果全是一样的数，就返回1
        int ans = 2;//这时结果至少是2
        int dir[2] = {1,-1};
        int now = 0;//now的意思是下次选择的符号，这次是递增，那就要选择-1，说明下次要递减
        if(nums[pos] < nums[pos+1]) now = 1;
        else now = 0;
        pos = pos+2;//比如这是的数组时1,3,5.之前pos指向1，这个时候应该让他指向5
        while(pos < nums.size()){
            if(nums[pos-1]*dir[now] < nums[pos]*dir[now]){//如果满足这次的递减或递增要求
                ans++;//结果+1
                pos++;//位置+1
                now++;//符号改变
                now = now%2;
            }
            else{
                pos++;//相当于把上一个元素出队列，再把这次的元素进队列
                //举例：比如1,2,5，3,在指向5的时候不是递减了，就应该把2出队列，换成
                //5，让高低差距尽量大，这就是贪心，有利于后面把小于5而不是小于2的数加进来
                //正确性：首先把2换成5不会影响现在的结果，只会让结果>=当前结果。
                //那如果在2开始把 2,5看做是交替数列的开头才能得到最大结果呢？这个时候
                //就相当于把2放缩成了1，结果还是对的。
            }
        
        }
        return ans;
    }

};