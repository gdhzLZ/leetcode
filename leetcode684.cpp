class Solution {
public:
    unordered_map<int,int>father;
    int Find(int x){
        if( x != father[x]){
            father[x] = Find(father[x]);
            return father[x];
        }
        return x;
    }
    bool Union(int x,int y){
        int e1 = Find(x);
        int e2 = Find(y);
        if(e1 != e2){
            father[e1] = e2;
            return true;
        }
        else return false;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        for(int i = 0 ;i < edges.size() ; i++){
            father[i] = i;
        }
        vector<int>ans;
        for(int i = 0 ; i < edges.size() ; i++){
            if(Union(edges[i][0],edges[i][1]) == false){
                ans.push_back(edges[i][0]);
                ans.push_back(edges[i][1]);
                return ans;
            }
        }
        return ans;
    }
};