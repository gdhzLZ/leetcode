class Solution {
public:
    unordered_map<int,pair<int,double>>father;
    int Find(int x){
        if(x != father[x].first){
            int t = father[x].first;
            father[x].first = Find(father[x].first);
            father[x].second *= father[t].second;
            
            return father[x].first;
        }
        return x;
    }
    void Union(int e1,int e2,double result){
        int f1 = Find(e1);
        int f2 = Find(e2);
        if(f1 != f2){
            father[f2].first = f1;
            father[f2].second = father[e1].second * result / father[e2].second;
        }
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        vector<double> ans;
        unordered_map<string,int> now;
        int numString = 1;
        for(int i = 0 ; i < equations.size() ; i++){
            int e1,e2;
            if(now[equations[i][0]] == 0){
                now[equations[i][0]] = numString++;
                father[numString-1].first = numString-1;
                father[numString-1].second = 1;
            }
            if(now[equations[i][1]] == 0){
                now[equations[i][1]] = numString++;
                father[numString-1].first = numString-1;
                father[numString-1].second = 1;
            }
            e1 = now[equations[i][0]];
            e2 = now[equations[i][1]];
            Union(e1,e2,values[i]);
          
        }
       
        for(int i = 0 ; i < queries.size() ; i++){
            if(now[queries[i][0]] == 0 || now[queries[i][1]] == 0){
                ans.push_back(-1.0);
                continue;
            }
                
            int e1 = now[queries[i][0]];
            int e2 = now[queries[i][1]];
            int f1 = Find(e1);
            int f2 = Find(e2);
            if(f1 != f2){
                ans.push_back(-1.0);
            }
            else{
                double temp = father[e1].second;
                double temp2 = father[e2].second;
                ans.push_back(temp2/temp);
            }
        }
       
        return ans;

    }
};