class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int maxx[26] = {0};
        int maxChar = 0;
        int num = 0;
        for(int i = 0  ; i < tasks.size() ; i++){
            int t = tasks[i]-'A';
            if(maxx[t] == 0) num++;
            maxx[t]++;
            if(maxx[maxChar] < maxx[t]) maxChar = t;
        }
        int nn = 0;
        for(int i = 0 ;  i< 26 ; i++){
                if(maxx[maxChar] == maxx[i])nn++;
        }
        int now = (maxx[maxChar]-1)*(n+1)+nn;
        return  now <tasks.size() ? tasks.size() : now;
    }
};