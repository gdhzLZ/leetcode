/*
这道题好好总结一下，滑动窗口的题应该就都会了。这个题不仅要记录t中的字母，还有次数
全都用visited数组解决，visited[i] 代表出现次数，未出现的为-1.设置窗口start end
当 碰到t中字母时，记录到visited 并统计这个时候出现字母的种类数（只有当每个字母出现的次数达到要求了种类数才会加1，所以也隐形检查了）是否满足要求，满足要求的话这是可能不是最终答案，因为这是的start可能还可以向后移动，检查办法是检测相应的visit数组是不是负数，是负数说明目前这个串中start指向的字母的个数多于要求的个数，然后移动到visited不是负数的地方，这是就是满足要求的串了。
*/
class Solution {
public:
    string minWindow(string s, string t) {
        
        int length = 0x3f3f3f3f;
        set<char> par;//相当于是字典库
        int visited[140] = {0};
        for(int i = 0 ; i < t.size() ; i++){
            visited[int(t[i])]++;
            par.insert(t[i]);
        }
        for(int i = 0 ; i< 140 ; i++)
            if(visited[i] ==0)visited[i] = -1;
        int sum = par.size();//static
        int start = 0,end = 0; //动态指针
        int now_num = 0; //暂时的num
        int ans_start = 0,ans_end = 0;//最终结果指针
        int tag = 0;
        while(end < s.size()){
            visited[int(s[end])]--;
            if(visited[int(s[end])] == 0){
                now_num++;
                if(now_num == sum){
                    while(visited[int(s[start])]<0){
                        if(par.find(s[start])!=par.end())//如果在par中，还要将visited进行++
                            visited[int(s[start])]++;
                        start++;//不管是不是par中都要start++
                        
                    }
                    if(length > end - start+1){
                        tag = 1;
                        length = end-start+1;
                        ans_start = start;
                        ans_end = end;
                    }
                    visited[int(s[start])]++;
                    start++;
                    now_num--;//这三个是一套，指针向后一个 visit改变，now_num也要改变

                }
            }
            end++;
        }
        if(tag == 0) return "";
        else return s.substr(ans_start,length);
    }
};