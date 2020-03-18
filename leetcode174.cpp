class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        
        if(dungeon.size() == 0)
            return 0;
        int col = dungeon[0].size(),row = dungeon.size();
        vector<vector<int>>dp(row,vector<int>(col,0x3f3f3f3f));
        dp[row-1][col-1] = 1;
        if(dungeon[row-1][col-1] >= 0)
            dungeon[row-1][col-1] = 0;
        for(int i = col-2 ; i>= 0 ; i--){
            dp[row-1][i] = dp[row-1][i+1]-dungeon[row-1][i+1];
            dp[row-1][i] = max(dp[row-1][i],1);
        }
        for(int i = row-2 ; i >= 0; i--){
            dp[i][col-1] = dp[i+1][col-1] - dungeon[i+1][col-1];
            dp[i][col-1] = max(dp[i][col-1],1);
        }
        for(int i = row-2 ; i >= 0 ; i--){
            for(int j = col-2 ; j>=0 ; j--){
                dp[i][j] = min(dp[i][j+1]-dungeon[i][j+1],dp[i+1][j]-dungeon[i+1][j]);
                dp[i][j] = max(dp[i][j],1);
            }
        }
        return max(dp[0][0]-dungeon[0][0],1);
    }
};