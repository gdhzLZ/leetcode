class Solution {
public:

    string longestPrefix(string s) {
       vector<int> match(s.size(),0);
        if(s=="")return "";
        match[0] = -1;
        for(int i = 1 ; i < match.size() ; i++){
            int pos = match[i-1];
            while(pos >= 0 && s[pos+1]!=s[i]){
                pos = match[pos];
            }
            if(s[pos+1] == s[i])
                match[i] = pos+1;
            else match[i] = -1;
        }
        int length = match[s.size()-1];
        if(length == -1)return "";
        else return s.substr(0,length+1);
    }
};