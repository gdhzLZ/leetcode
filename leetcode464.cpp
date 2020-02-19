class Solution {
public:
    bitset<(1<<21)> visited,status;//visited记录有没有被访问过，status记录访问过的真值
    bool dfs(int nowStatus,int maxChoosableInteger, int desiredTotal){
        if(visited[nowStatus] == 1) return status[nowStatus];
        bool now = false;
        for(int i = maxChoosableInteger ; i >= 1 ; i--){
            if((nowStatus>>i)&1==1) continue;//测试这个位是否是1，是1表示使用了，则不能再用
            if(i >= desiredTotal){
                now = true;//找到了结果要退出
                break;
            } 
            else{
                int nowStatusTemp = nowStatus|(1<<i);//取出这个数，把相应的位 置1
                now = !dfs(nowStatusTemp,maxChoosableInteger,desiredTotal-i);
                if(now == true) break;//如果找到了可以赢的办法，防止覆盖，所以要退出
            }
        }
        visited[nowStatus]=1;
        status[nowStatus] = now;
        return now;
    }
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        int sum = (1+maxChoosableInteger)*maxChoosableInteger/2;
        if(sum < desiredTotal) return false;
        if(maxChoosableInteger >= desiredTotal) return true;
        return dfs(0,maxChoosableInteger,desiredTotal);
    }
};