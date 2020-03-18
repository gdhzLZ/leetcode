class Solution {
public:
    double frogPosition(int n, vector<vector<int>>& edges, int t, int target) {
        if(n == 1)
            return 1;
        vector<int>leave(n+1,0);
        queue<int> leaves;
        vector<int>father(n+1);
        vector<int>sonNum(n+1,0);
        bool visited[103] = {false};
        for(int i = 0 ;  i < edges.size() ; i++){
            leave[edges[i][0]]++;
            leave[edges[i][1]]++;
        }
        for(int i = 2 ; i < leave.size() ; i++){
            if(leave[i] == 1){
                leaves.push(i);
                visited[i] = true;
            }
        }
        while(!leaves.empty()){

            int nowNode = leaves.front();
            leaves.pop();
            
            for(int i = 0 ; i < edges.size() ; i++){
                if(edges[i][0] == nowNode){
                    father[nowNode] = edges[i][1];
                    sonNum[edges[i][1]]++;
                    if(visited[edges[i][1]] == false &&edges[i][1] != 1 ){
                        leaves.push(edges[i][1]);
                        visited[edges[i][1]] = true;
                    }
                    break;
                }
                else if(edges[i][1] == nowNode){
                    father[nowNode] = edges[i][0];
                    sonNum[edges[i][0]]++;
                    if(visited[edges[i][0]] == false &&edges[i][0] != 1 ){
                        leaves.push(edges[i][0]);
                        visited[edges[i][0]] = true;
                    }
                    break;
                }
            }
        }
        double ans = 1;
        int nowPos = target;
        while(t != 0 && nowPos!= 1){
            t--;
            nowPos = father[nowPos];
            ans*=(1.0*sonNum[nowPos]);
        }
        if(nowPos!= 1){
                return 0.0;
        }
        else if(t == 0){
            return 1.0/ans;
        }
        else{
            if(sonNum[target] == 0)
                return 1.0/ans;
            else return 0.0;
        }
        
        

    }
};