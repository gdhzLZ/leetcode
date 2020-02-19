class Solution {
public:
    string removeDuplicateLetters(string s) {
        string ss = "";
        vector<vector<int>> ans(26);//每个字母在字符串中出现的位置
        set<int> now;//最终要在字符串中出现的字母集合
        int length = 0;
        for(int i = 0 ; i < s.size() ; i++){
            int pos = s[i]-'a';
            ans[pos].push_back(i);
            if(now.find(pos) == now.end()) length++,now.insert(pos);
        }
        set<int> End;
        set<int>::iterator it;
        for(it = now.begin(); it != now.end() ; it++){
            int pos = *it;
            vector nn = ans[pos];
            End.insert(ans[pos][nn.size()-1]);
            
        }
        //每次都从最小的字母遍历，如果他满足先出现的条件（所有没出现的字符在他后面还会出现，
        //也就是当前坐标，小于所有没出现字符最后一次出现的坐标），就让他先出现，并把它删除
        while(!now.empty()){
            set<int>::iterator it;
            for(it = now.begin() ; it != now.end() ; it++){
                if(ans[*it][0] > *End.begin())
                    continue;
                int l = ans[*it].size();
                //删除每个字母在End最大坐标
                int nowEnd = ans[*it][l-1];
                End.erase(nowEnd);
                //删除所有比当前位置大的坐标
                for(int i = 0 ; i < 26 ; i++){
                    if(ans[i].empty())continue;
                    int pos = 0;
                    while(pos < ans[i].size() && ans[i][pos]< ans[*it][0])
                        pos++;
                    ans[i].erase(ans[i].begin(),ans[i].begin()+pos);
                }
                //删除当前处理完的ans中的vector,也不不删哈哈，反正不会在处理这个vector了
                //删除这次处理的字母
                int tt = *it;
                now.erase(tt);
                char c = 'a'+tt;
                ss+=c;
                break;
            }
        }
        return ss;
    }
};