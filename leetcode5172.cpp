class Solution {
    int cnt[10],sum;
    string ans = "";
    int del(int m)
    {
        for(int i=m;i<=9;i+=3)if(cnt[i]){cnt[i]--;return 1;}
        return 0;
    }
public:
    string largestMultipleOfThree(vector<int>& d) {
        for(auto x:d)cnt[x]++,sum+=x;
        if(cnt[0]==d.size())return "0";
        if(sum%3==1)if(!del(1))del(2),del(2);
        if(sum%3==2)if(!del(2))del(1),del(1);
        for(int i=9;i>=0;i--)while(cnt[i]--)ans+=i+'0';
        return ans;
    }
};

