class Solution {
public:
    unordered_map<int,int>father;
    int Find(int x){
        if(x!=father[x]){
            father[x] = Find(father[x]);
            return father[x];
        }
        return x;
    }
    void Union(int x,int y){
        int e1 = Find(x);
        int e2 = Find(y);
        if(e1 != e2){
            father[e1] = e2;
        }
    }
    int findCircleNum(vector<vector<int>>& M) {
        for(int i = 0 ; i < M.size() ; i++)
            father[i] = i;
        for(int i = 0 ; i < M.size() ; i++){
            for(int j = i+1 ; j < M[0].size() ; j++){
                if(M[i][j] == 1){
                    Union(i,j);
                }
            }
        }
        set<int> Friend;
        for(int i = 0 ; i < M.size() ; i++){
            int t = Find(i);
            Friend.insert(t);
        }
        return Friend.size();
    }
};