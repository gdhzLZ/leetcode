class Solution {
public:
//dp[i] = min(dp[j] +1) for str[j:i] huiwen
    int minCut(string s) {
        vector<int> dp(s.size());
        for(int i = 0 ; i < s.size() ; i++)
            dp[i] = i;
        vector<vector<bool>> checkpalindrome(s.size(),vector<bool>(s.size(),false));
        for(int right = 0 ; right < s.size(); right++){
            for(int left = 0 ; left <= right ; left++)
                if(s[right] == s[left] &&(right-left <= 2 || checkpalindrome[left+1][right-1]))
                    checkpalindrome[left][right] = true;
        }
       
        for(int i = 0 ; i < s.size() ; i++){
            if(checkpalindrome[0][i])
                dp[i] = 0;
            else{
                for(int j = 1 ; j <= i ; j++){
                    if(checkpalindrome[j][i])
                        dp[i] = min(dp[i],dp[j-1]+1);
                }
            }
        }
        return dp[s.size()-1];

    }
};