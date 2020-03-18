class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<bool> visited(manager.size(),false);
        vector<int> Cost(manager.size(),0);

        for(int i = 0 ; i < manager.size() ; i++){
            if(manager[i] != -1)
                visited[manager[i]] = true;
        }
        
        queue<int> Q;
        for(int i = 0 ; i < visited.size() ; i++){
            if(visited[i] == false){
                //cout << i << endl;
                Q.push(i);
            }
        }
        if(Q.empty()) return 0;
        
        while(!Q.empty()){
            int loop = Q.size();
            set<int> Insert;
            while(loop--){
                int now = Q.front();
                Q.pop();
                if(now == headID)
                    break;
                
                if(Cost[now] +informTime[manager[now]] > Cost[manager[now]]){
                    Cost[manager[now]] = Cost[now] +informTime[manager[now]];
                    //cout <<Cost[manager[now]] <<endl;
                }
                if(Insert.find(manager[now]) == Insert.end()){
                    Q.push(manager[now]);
                    Insert.insert(manager[now]);

                }
                
            }
           
        }
        return Cost[headID];
    }
};