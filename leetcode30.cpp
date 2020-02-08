class Solution {
public:
    
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ans;
        if(s.size() == 0 || words.size() == 0) return ans;
        map<string,int> Map;
        int wordLength = words[0].size();
        int windowsLength = wordLength*words.size();
        if(s.size() < windowsLength) return ans;
        for(int i = 0 ;  i < words.size() ; i++){
            if(Map.find(words[i]) != Map.end()) Map[words[i]]++;
            else Map[words[i]] = 1;
        }
        for(int i = 0 ; i <= s.size()-windowsLength ; i++){
            map<string,int> temp_Map = Map;
            int j;
            for( j = 0 ; j < windowsLength;j+=wordLength){
                if(temp_Map.find(s.substr(i+j,wordLength))!=temp_Map.end()){
                    int t = --temp_Map[s.substr(j+i,wordLength)];
                    if(t == 0)
                        temp_Map.erase(s.substr(j+i,wordLength));
                }
                else break;
            }
            if(j == windowsLength) ans.push_back(i);
        }
        return ans;
    }
};