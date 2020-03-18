class Solution {
public:
    bool isIncrease(int num){
        string temp = to_string(num);
        char c = temp[0];
        for(int i = 1 ; i < temp.size() ; i++){
            if(c > temp[i])
                return false;
            c = temp[i];
        }
        return true;
    }
    int nine(int length){
        string ans = "";
        while(length--)
            ans+='9';
        return atoi(ans.c_str());
    }
    int monotoneIncreasingDigits(int N) {
        if(isIncrease(N))
            return  N;
        int cir = 1;
        int ans;
        while(1){
            int nowDi = pow(10,cir);
            int t1 = N/nowDi;
            int t2 = N%nowDi;
            t1--;
            ans = t1*nowDi+nine(cir);
            if(isIncrease(ans))
                break;
            cir++;
        }
        return ans;
    }
};