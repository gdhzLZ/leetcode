class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int num5 = 0;
        int num10 = 0;
        for(int i = 0 ; i < bills.size() ; i++){
            if(bills[i] == 5)
                num5++;
            else if(bills[i] == 10){
                if(num5 == 0)
                    return false;
                num5--;
                num10++;
            }
            else{
                if(num10 != 0 && num5 !=0 ){
                    num10--;
                    num5-=1;
                }
                else if(num5 >= 3)
                    num5-=3;
                else return false;
            }
        }
        return true;
    }
};