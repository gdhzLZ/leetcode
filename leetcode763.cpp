class Solution {
public:
    vector<int> partitionLabels(string S) {
        vector<vector<int>> section;
        vector<bool> visited(26,false);
        for(int i = 0 ; i < S.size() ; i++){
           
            if(visited[S[i]-'a'] == false){
                visited[S[i]-'a'] = true;
                vector<int> temp;
                temp.push_back(i);
                temp.push_back(i);
                section.push_back(temp);
            }
            else{
                while(1){
                    int be = section[section.size()-1][0];
                    int en = section[section.size()-1][1];
                    if(S.substr(be,en-be+1).find(S[i]) != -1){
                        section[section.size()-1][1] = i;
                        break;
                    }
                    else{
                        section.pop_back();
                    }
                }
            }
        }
        vector<int> ans;
        for(vector<int> now : section){
            ans.push_back(now[1]-now[0]+1);
        }
        return ans;
    }
};