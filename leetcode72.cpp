class Solution {
public:
    int minDistance(string word1, string word2) {
        word2 = "#"+word2;
        vector<int> dp(word2.size(), 0);
        for(int j = 0 ; j < word2.size();j++){
            dp[j] = j;
            
        }
        for(int i = 0 ; i < word1.size();i++){
            vector<int> temp(word2.size()+1, 0);
            for(int j = 0 ; j < word2.size();j++){
                if(j == 0){
                    temp[0] = i+1;
                    //cout << temp[j] <<" ";
                    continue;
                }
                int t = min(dp[j-1],min(dp[j],temp[j-1]));
                temp[j] = t+1;
                if(word2[j] == word1[i]) temp[j] = min( temp[j],dp[j-1]);
               // cout << temp[j] <<" ";
            }
            //cout << endl;
            dp = temp;
        }
        return dp[word2.size()-1];
    }
};