class Solution {
public:
    void Merge(vector<long long>& ans,int left,int right,int& re){
        vector<long long>temp_ans;
        int mid = (left+right)/2;
        int now_left = left,now_right = mid+1;
        
        while(now_left < mid+1 && now_right < right+1){
            if(ans[now_left] <= ans[now_right]){
                temp_ans.push_back(ans[now_left]);
                now_left++;
            }
            else{
                temp_ans.push_back(ans[now_right]);
                now_right++;
            }
        }
        while(now_left < mid+1){
            temp_ans.push_back(ans[now_left]);
            now_left++;
        }
        while(now_right < right+1){
            temp_ans.push_back(ans[now_right]);
            now_right++;
        }
        for(int i = 0 ;  i < temp_ans.size() ; i++)
            ans[left+i] = temp_ans[i];
       
    }
    void findRangeSum(vector<long long>& ans,int left,int right,int lower,int upper,int& re){
        int mid = (left+right)/2;
        int temp_left = left;
        int temp_lower = mid+1,temp_upper = mid+1;//卧槽 卡在这里半小时，这句话放在while里面会超时，看来赋值语句能放在循环外面就放在循环外面。
        while(temp_left<=mid){
            while(temp_lower<=right &&  ans[temp_lower] -ans[temp_left] < lower){
                temp_lower++;
            }
            while(temp_upper <= right && ans[temp_upper] -ans[temp_left]<=upper){

               temp_upper++;
            }
            re+=temp_upper-temp_lower;
            //////////////////////
            temp_left++;
        }
       
                
    }
    void Sort(vector<long long>& ans,int left,int right,int lower,int upper,int& re){
        if(left == right){// 有序了
            if(ans[left]<=upper&&ans[left] >=lower)re++;
            return;
        }
        int mid = (left+right)/2;
        Sort(ans,left,mid,lower,upper,re);
        Sort(ans,mid+1,right,lower,upper,re);
        findRangeSum(ans,left,right,lower,upper,re);
        Merge(ans,left,right,re);
    }
    int countRangeSum(vector<int>& nums, int lower, int upper) {
       
        cout << endl;
        int re = 0;
        vector<long long> temp;
        if(nums.size() == 0 || lower > upper) return 0;
        long long  sum = 0;
        for(int i = 0 ; i < nums.size(); i++){
            sum += nums[i];
            temp.push_back(sum);
            
        }
        int t = temp.size()-1;
        Sort(temp,0,t,lower,upper,re);
       
        
        return re;
    }
};