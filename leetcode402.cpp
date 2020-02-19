class Solution {
public:
    string removeKdigits(string num, int k) {
        int length = 0;
        int pos = 0;
        while( length< k && num.size() != 0){
            if(pos == num.size()-1)
                num.erase(0,1),pos--,length++;
            else{
                while(pos+1 < num.size() && num[pos] <= num[pos+1])
                    pos++;
                num.erase(pos,1);
                pos--;
                if(pos <= 0 ) pos = 0;
                length++;
            }
            while(num.size() != 0 && num[0] == '0')
                num.erase(0,1);
        }
        if(num.size() == 0) return "0";
        else return num;
    } 
};