class Solution {
public:
    void dfs(vector<string> &ans,vector<vector<int>> &space,string &s,string temp,int pos){
        
       
        for(int i = 0 ; i < space[pos].size() ; i++){
            string temp2;
            if(pos == space[pos][i]){
                if(temp.size() != 0)
                    temp2 =  s.substr(0,pos+1) +" "+ temp;
                else 
                    temp2 = s.substr(0,pos+1);
                ans.push_back(temp2);
            }
            else{
                if(temp.size() != 0)
                    temp2 = s.substr(space[pos][i]+1,pos-space[pos][i])+" "+temp;
                else 
                    temp2 = s.substr(space[pos][i]+1,pos-space[pos][i]);
                dfs(ans,space,s,temp2,space[pos][i]);
            }
            
        }
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<vector<int>> space(s.size());
        vector<string> ans;
        set<string> dict;
        for(string i: wordDict)
            dict.insert(i);
        for(int i = 0 ; i < s.size() ; i++){
            if(dict.find(s.substr(0,i+1)) != dict.end())
                space[i].push_back(i);
            for(int j = 0; j< i ; j++){
                if(space[j].size() != 0 &&dict.find(s.substr(j+1,i-j))!=dict.end()){
                    space[i].push_back(j);
                }
            }
        }
       
        dfs(ans,space,s,"",s.size()-1);
        return ans;
        
    }
};