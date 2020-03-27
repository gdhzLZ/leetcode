class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if(matrix.size() == 0)
            return 0;
        vector<vector<int>>dp(matrix.size(),vector<int>(matrix[0].size(),0));
        for(int i = 0 ; i < matrix.size() ; i++){
            for(int j = 0 ; j < matrix[0].size() ; j++){
                if(i == 0)
                    dp[i][j] = matrix[i][j]-'0';
                else{
                    if(matrix[i][j] == '1')
                        dp[i][j] = dp[i-1][j]+1;
                    else dp[i][j] = 0;
                }
            }
        }
        int ans = 0;
        vector<int> empty;
        for(vector<int> now :dp){
            vector<int> Q = empty;
            int tempAns = 0;
            for(int i = 0 ; i < now.size() ; i++){
                if(Q.empty() || Q[Q.size()-1] <= now[i]){
                    Q.push_back(now[i]);
                }
                else{
                    int j = Q.size()-1;
                    int width = 1;
                    while(j >= 0 && Q[j] > now[i]){
                        if(width <= Q[j]){
                            tempAns = max(tempAns,width*width);
                        }
                        Q[j] = now[i];
                        width++;
                        j--;
                    }
                    if(now[i] == 0) Q = empty;
                    else  Q.push_back(now[i]);
                }
            }
            int width = 1;
            for(int i = Q.size()-1 ; i >=0  ; i--){
                if(width <= Q[i]){
                    tempAns = max(tempAns,width*width);
                    width++;
                }
                else break;
                
            }
            ans = max(tempAns,ans);
        }
        return ans;
    }
};