class Solution {
public:
    vector<string> ans;
    void dfs(int left,int right,string nowString){
        if(left == 0){
            nowString += ')';
            right--;
            if(right == 0){
                ans.push_back(nowString);
                nowString = "";
                return;
            }
            else{
                dfs(left,right,nowString);
            }
        }
        else{
            if(left < right){
                string temp =  nowString+")";
                dfs(left,right-1,temp);
                temp = nowString+'(';
                dfs(left-1,right,temp);
            }
            else if(left == right){
                string temp = nowString+'(';
                left--;
                dfs(left,right,temp);
            }
        }
        return;
    }
    vector<string> generateParenthesis(int n) {
        string now = "";
        dfs(n,n,now);
        return ans;
    }
};