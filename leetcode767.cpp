class Solution {
public:
    typedef struct N{
        char q;
        int num = 0;
        bool operator < (const struct N & a)const{
            if(num != a.num)
                return num < a.num;
            else return q < a.q;
        }
    }node;
    string reorganizeString(string S) {
        string ans = "";
        priority_queue<node> Q;
        if(S.size() == 0)
            return ans;
        node num[26] = {0};
        for(int i = 0 ; i < S.size() ; i++)
            num[S[i]-'a'].num++,num[S[i]-'a'].q = S[i];
        for(int i = 0 ; i < 26 ; i++)
            if(num[i].num!=0)
                Q.push(num[i]);
        while(!Q.empty()){
            node temp = Q.top();
            Q.pop();
            ans+=temp.q;
            temp.num--;
            if(!Q.empty()){
                node temp2 = Q.top();
                Q.pop();
                ans+=temp2.q;
                temp2.num--;
                if(temp2.num!=0)
                    Q.push(temp2);
            }
            else if(Q.empty() && temp.num != 0 )
                return "";
            if(temp.num != 0)
                Q.push(temp);
            
        }
        return ans;
    }
};