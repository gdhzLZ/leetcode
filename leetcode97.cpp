class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int length = 0;
        int pos1 = 0,pos2 = 0;
        if(s1.size()+s2.size() != s3.size()) return false;
        vector<vector<bool>> dp(s2.size()+1,vector<bool>(s1.size()+1,false));
        dp[0][0] = true;
        for(int i = 0 ; i < s1.size() ; i++){
            if(s1[i] == s3[i])
                dp[0][i+1] = true;
            else break;
        }
        for(int i = 0; i < s2.size() ; i++){
            if(s2[i] == s3[i])
                dp[i+1][0] = true;
            else break;
        }
       
        for(int i = 0 ; i < s2.size() ;i++){
            for(int j = 0 ; j < s1.size() ; j++){
                dp[i+1][j+1] = (dp[i][j+1]&&s2[i]==s3[i+j+1] )||(dp[i+1][j]&&s1[j]==s3[i+j+1] );
            }
        }
       
        return dp[s2.size()][s1.size()];
    }
};