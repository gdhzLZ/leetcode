class Solution {
public:
int gcd(int a, int b)     
{
	int temp;
	if(a<b)     //通过比较求出两个数中的最大值和最小值
	{
		temp = a;
		a = b;
		b = temp;
	}
	while(b!=0)     //通过循环求两数的余数，直到余数为0
	{
		temp = a%b;
		a = b;
		b = temp;
	}
	return a;     //返回最大公约数到调用函数处
}
    int NOW_N(int n,long long  a,long long  b,long long  c){//返回n前面有多少个丑数
        int g1 = gcd(a,c),g2 = gcd(a,b),g3 = gcd(b,c);
        long long little_ab = a*b/g2,little_bc = b*c/g3,little_ac = a*c/g1;
        long long t1 = n/a,t2 = n/b,t3 = n/c,t4 = n/little_ac,t5=n/little_ab,t6=n/little_bc;  
        long long t7;
        t7 = a*t6/gcd(a,t6);
        return t1+t2+t3-t4-t5-t6+t7;
    }
    int nthUglyNumber(int n, int a, int b, int c){
        if(n == 1) return min(a,min(b,c));
        long long left = 1,right = 2*pow(10,9);
        while(left < right){
            long long mid = (left+right)/2;
            int t = NOW_N(mid,a,b,c);
            if(n > t){
                left = mid+1;
            }
            else right = mid;
           
        }
        cout << left << endl;
        int a1 = abs(left/a*a);
        int a2 = abs(left/b*b);
        int a3 = abs(left/c*c);
        return max(a1,max(a3,a2));
    }
};