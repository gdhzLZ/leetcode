class Solution {
public:
    void dfs(vector<vector<char>>& grid,int posx,int posy){
        if(posx < 0 || posy < 0 || posx >= grid.size() || posy >= grid[0].size())
            return;
        if(grid[posx][posy] != '1')
            return;
        int dir[4][2] = {{-1,0},{1,0},{0,1},{0,-1}};
        grid[posx][posy] = '0';
        for(int i = 0 ; i < 4 ; i++){
            dfs(grid,posx+dir[i][0],posy+dir[i][1]);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        if(grid.size() == 0)
            return 0;
        int ans = 0;
        
        for(int i = 0 ; i < grid.size() ; i++){
            for(int j = 0; j < grid[0].size() ; j++){
                if(grid[i][j] == '1'){
                    ans++;
                    dfs(grid,i,j);
                }
            }
        }
        return ans;
    }
};