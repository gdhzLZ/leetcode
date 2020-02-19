class Solution {
public:
    vector<vector<int>> ans;
    void dfs(int nowLength,int length,vector<int>& now,vector<int>& nums,int pos){
        if(nowLength == length){
            ans.push_back(now);
            return;
        }
        for(int i = pos+1 ; i < nums.size() ; i++){
            now.push_back(nums[i]);
            //cout << nums[i] << endl;
            dfs(nowLength+1,length,now,nums,i);
            now.pop_back();
        }
        return;

    }
    vector<vector<int>> subsets(vector<int>& nums) {
        if(nums.size() == 0){
            vector<int> now;
            ans.push_back(now);
            return ans;
        }
        vector<int> em;
        vector<int> now;
        for(int i = 0 ; i <= nums.size() ; i++){
            dfs(0,i,now,nums,-1);
            now = em;
            //cout << "wan cheng " << endl;
        }
        return ans;
    }
};