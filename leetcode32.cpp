class Solution {
public:
    int longestValidParentheses(string s) {
        vector<int> tag(s.size()+1,0);
        if(s.size() == 0) return 0;
        stack<int> S;
        int nowPair = 0;
        int now = 0;//当前存在的最长的括号对 ()()这个时候的now就是2，()(这个时候的now就是0 
        for(int i = 0 ;  i < s.size() ; i++){
            if(s[i] == '('){
                S.push(i);
                tag[i] = now;
                now = 0; //目的是如果下次匹配到的左括号之间没有括号对时就是0
            }
            else{
                if(!S.empty()){
                    int t = S.top();
                    S.pop();
                    if(nowPair<now+1+tag[t]) {
                        nowPair = now+1+tag[t];
                    }
                    now = now+1+tag[t];
                }
                else {
                    now = 0; //如果是空 就肯定不会有
                }

            }
        }
        return nowPair*2;
    }
};