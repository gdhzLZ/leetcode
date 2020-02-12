class Solution {
public:
    bool isScramble(string s1, string s2) {
        if(s1.size() != s2.size()) return false;
        if(s1 == "" && s2 == "") return true;
        bool dp[100][100][100];
        for(int len = 1 ; len <= s1.size() ; len++){
            for(int i = 0 ; i+len <= s1.size() ; i++){
                for(int j = 0  ; j+len <= s2.size();j++){
                    if(len == 1)
                        dp[len][i][j] = (s1[i] == s2[j]);
                    else{
                        for(int q = 1 ; q < len ; q++){
                           // cout << len << " " << i << " " << j << " " << q << endl;
                            dp[len][i][j] = ((dp[q][i][j]&&dp[len-q][i+q][j+q])||(dp[q][i][j+len-q]&&dp[len-q][i+q][j]));
                            if(dp[len][i][j])break;
                        }
                    }
                }
            }
        }
        return dp[s1.size()][0][0];
    }
};