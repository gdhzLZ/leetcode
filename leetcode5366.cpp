class Solution {
public:
    int visited[300][300] = {0};
    int dir[7][2];

    bool dfs(vector<vector<int>>& grid,int wantdir,int posx,int posy){
        if(posx <0 || posx >= grid.size() || posy < 0||posy >=grid[0].size())
            return false;
        int d1 = dir[grid[posx][posy]][0],d2 = dir[grid[posx][posy]][1];
        if(wantdir!=d1&&wantdir!=d2)
            return false;
        if(visited[posx][posy] == 1)return false;
        visited[posx][posy] = 1;
        if(posx == grid.size()-1&&posy == grid[0].size()-1)
            return true;
        int next;
        if(wantdir==d1){
            wantdir = (d2+2)%4;
            next = d2;
        }
        else{
            wantdir =(d1+2)%4;
            next = d1;
        }
        if(next == 0) return dfs(grid,wantdir,posx,posy-1);
        else if(next == 1) return dfs(grid,wantdir,posx-1,posy);
        else if(next == 2) return dfs(grid,wantdir,posx,posy+1);
        else return dfs(grid,wantdir,posx+1,posy);
    }
    bool hasValidPath(vector<vector<int>>& grid) {
        dir[1][0] =0;dir[1][1] = 2;
        dir[2][0] =1;dir[2][1] = 3;
        dir[3][0] =0;dir[3][1] = 3;
        dir[4][0] =2;dir[4][1] = 3;
        dir[5][0] =0;dir[5][1] = 1;
        dir[6][0] =1;dir[6][1] = 2;
        return (dfs(grid,0,0,0)||dfs(grid,1,0,0)||dfs(grid,2,0,0)||dfs(grid,3,0,0));
    }
};