class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool>dp(s.size(),false);
        set<string>Dict;
        for(string i : wordDict){
            Dict.insert(i);
        }
        for(int i = 0 ;  i < dp.size() ; i++){
            if(Dict.find(s.substr(0,i+1)) != Dict.end()){
                dp[i] = true;
                continue;
            }
            for(int j = 0 ; j < i ; j++){
                if(dp[j]&&Dict.find(s.substr(j+1,i-j))!=Dict.end()){
                    dp[i] = true;
                    break;
                }
                    
            }
        }
        return dp[s.size()-1];
    }
};