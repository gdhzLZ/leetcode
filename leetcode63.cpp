class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        
        long long dp[110][110] = {0} ;
        //memset(dp,0,sizeof(dp));
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j< n ; j++){
                if(i == 0 && j == 0){
                    if(obstacleGrid[i][j] != 1) dp[i+1][j+1] = 1;
                    continue;
                }
                if(obstacleGrid[i][j] == 1) continue;
                dp[i+1][j+1] = dp[i][j+1] + dp[i+1][j];
            }
        }
        return dp[m][n];
    }
};