class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int ans = 0;
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        for(int i = 0 ; i < s.size() ; i++){
            if(g.size() == 0) break;
            if(s[i] < g[0]){
            }
            else{
                ans++;
                g.erase(g.begin());
            }
        }
        return ans;
    }
}; 