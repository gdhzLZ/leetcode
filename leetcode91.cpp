class Solution {
public:
    int numDecodings(string s) {
        vector<int> dp(s.size(),0);
        vector<int> dpDan(s.size(),0);//记录以当前单个字符结尾的，即当前字符一个数结尾的
        //个数 比如 1 2 dpDan[1]（1是指针，指向数字2）等于1。1232，dpDan[3] = 2,因为
        //1,2，3,2和12,3,2。
        if(s == "") return 0;
        if(s[0] !='0'){
            dp[0] = 1;
            dpDan[0] = 1;
        }
        
        for(int i = 1 ; i < s.size() ; i++){
            if(s[i] != '0') dp[i]+=dp[i-1],dpDan[i] = dp[i];
            int tt = atoi(s.substr(i-1,2).c_str());
            //cout << tt <<endl;
            if(s[i-1]!='0'&&tt>0&&tt<=26){
                dp[i]+=dpDan[i-1];
            }
        }
        return dp[s.size()-1];
    }
};