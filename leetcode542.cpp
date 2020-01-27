/*
首先说一句自己太菜了，这么简单地题做了很长时间
这道题跟迷宫题很像，只不过这道题相当于是多个出口。
先把所有的0全都压入队列，然后逆向bfs
判断是否入队列的条件就看这个点之前有没有入队列过
如果没有如果队列，就一定是1，此时也一定是到达这个位置的最短位置。
这个题学习两点：1.记住方向遍历的简单写法2.二维vector确定大小和初始化的写法
*/
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        int visited[10003] = {0};
        int r = matrix.size();int c = matrix[0].size();
        vector<vector<int>> ans(r, vector<int>(c,0)); 
        queue<pair<int,int>> now;
        for(int i = 0 ; i < r ; i++){
            for(int j = 0 ; j < c ; j++){
                if(matrix[i][j] == 0){
                    visited[i*c+j] = 1;
                    now.push(make_pair(i,j));
                }
            }
        }
        int length = 1;
        vector<vector<int>> dir = {{-1,0}, {0,-1}, {1,0}, {0,1}};
        while(!now.empty()){
            int loop = now.size();
            cout << loop <<endl;
            for(int i = 0 ; i < loop ; i++){
                pair<int,int> temp = now.front();
                now.pop();
                for(int j = 0 ; j < 4 ; j++){  
                    int a = temp.first + dir[j][0];
                    int b = temp.second + dir[j][1];
                    if(a>=0&&a<r&&b>=0&& b<c&&visited[a*c+b]!=1){
                        
                        ans[a][b] = length;
                        visited[a*c+b] = 1;
                        now.push(make_pair(a,b));
                    }
                }
            }
            length++;
        }
        return ans;
    }
};