class Solution {
public:
    string longestPalindrome(string s) {
        if(s == "") return "";
        string ans = "";
        string sr = s;
        reverse(sr.begin(),sr.end());
        int visited[1003] = {0};
        int temp_last = 0;
        int end = 0,length = 0;
        for(int i = 0 ; i < sr.size() ; i++){
            int upLeft = 0;
            for(int j = 0 ; j < s.size();j++){
                int vv = 0;
               if(s[j] == sr[i]) {
                  vv = 1+upLeft; 
                  if(length <= vv && i+j-vv+1 == s.size()-1){ //这里是关键
                  //把字符串倒过来之后只是匹配最长字串还不行，可能有这种情况，
                  //aacbdfcaa 这个串和倒过来的串最长字串是aac是不对的
                  //所以还要判断这个时候匹配的串和原来是不是一个位置
                  //用这个时候的坐标i-vv+1得到回文串在反转串起始位置
                  //如果加上j等于等于总长度-1 就符合条件了。
                      length = vv;
                      end = j;
                  }
               }
               upLeft = visited[j];
               visited[j] = vv;

            }
           
        }
        return s.substr(end-length+1,length);
    }
};