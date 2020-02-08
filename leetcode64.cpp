class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if(grid.size() == 0) return 0;
        vector<int> path(grid[0].size()+1,0x3f3f3f3f);
        for(int i = 0 ; i < grid.size(); i++){
            for(int j = 0 ; j < grid[0].size() ; j++){
                if(j == 0 && i == 0) {
                    path[j+1] = grid[i][j];
                    continue;
                }
                path[j+1] = min(path[j],path[j+1])+grid[i][j];//滚动数组 path[j]
                //相当于左边的,path[j+1]是上面的
                
            }
            
        }
        int m = grid[0].size();
        return path[m];
    }
}; 