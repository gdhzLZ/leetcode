class Solution {
public:
    string getSum(string n1, string n2) {
    //从后往前加
    string sum;
    //进位
    int carry = 0;
    //注意哦，i 的初始值为 1 。
    for (unsigned int i = 1; i <= n1.length() || i <= n2.length(); i++)
    {
        int n = carry;
        //从后向前取字符串每个下标的字符
        //根据美国信息交换标准代码（即常称的 ASCII ）可知，字符 0 的十进制码表示为 48，所以在此需要减去 48 。
        n += i <= n1.length() ? n1[n1.length() - i] - 48 : 0;
        n += i <= n2.length() ? n2[n2.length() - i] - 48 : 0;
        carry = n / 10;
        n %= 10;
        //将整数转换为字符，所以加上 48 。
        //（在开头插入 1 个字符）
        sum = sum.insert(0,1,char(n + 48));
    }
    if (carry > 0)
        sum = sum.insert(0,1, '1'); ;
    return sum;
}
    bool isAdditiveNumber(string num) {
        for(int i = 0 ; i < num.size()/2 ;i++){
            for(int j = i+1; j < num.size()-1  ; j++){
                string a1 = num.substr(0,i+1);
                string a2 = num.substr(i+1,j-i);
                if((a1[0] == '0'&&i+1>1) ||(a2[0] == '0' &&j-i>1))continue;
                int pos = j;
                while(pos < num.size()-1){
                    
                    string a = getSum(a1,a2);
                    if(num.substr(pos+1,num.size()-pos-1).find(a) == 0){
                        a1 = a2;
                        a2 = a;
                        pos += a.size();
                    }
                   
                    else{
                        break;
                    } 
                }
                if(pos == num.size()-1) return true;
            }
            
        }
        return false;
    }
};