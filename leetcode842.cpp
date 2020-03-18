class Solution {
public:
    vector<int> ans;
    int tag = 0;
    int MAX_VALUE = pow(2,31)-1;
    void dfs(string s,long a,long b){
        //cout << a << " " << b << endl;
        if(s == ""){
            if(ans.size() >= 3)
                tag = 1;
            return;

        }
        if(tag == 1)
            return ;
        long c = a+b;
        if(c > MAX_VALUE )
            return;
        string now = to_string(c);
        if(s.find(now) != 0)
            return;
        ans.push_back(c);
        if(s.size()-now.size() >= 0)
            dfs(s.substr(now.size(),s.size()-now.size()),b,c);
        if(tag != 1)
            ans.pop_back();
        return;
    }
    vector<int> splitIntoFibonacci(string S) {
        if(S.size() < 3) return ans;
        for(int i = 0  ; i < S.size() ; i++){
            long a = atol(S.substr(0,i+1).c_str());
            if(a > MAX_VALUE)
                break;
            ans.push_back(a);
            for(int j = i+1 ; j < S.size() ; j++){
                long b = atol(S.substr(i+1,j-i).c_str());
                if(b > MAX_VALUE)
                    break;
                ans.push_back(b);
                dfs(S.substr(j+1,S.size()-j-1),a,b);
                if(tag == 1)
                    break;
                ans.pop_back();
                if(S[i+1] == '0')
                    break;
            }
            if(tag == 1)
                break;
            ans.pop_back();
            if(S[0] == '0')
                break;
        }
        if(tag == 1)
            return ans;
        vector<int> _;
        return _;
    }
}; 