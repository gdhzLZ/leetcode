class Solution {
public:
int sumFourDivisors(vector<int>& nums) {
	vector< int> rec(100005, 0);//记录是否是素数 
	vector< int> prime;//素数集
	using ll = long long int;
    
    //oura查找	
    for (int i = 2; i < 50001; i++) {
		if (!rec[i])
			prime.push_back(i),cout << i << endl;
		for (auto& p : prime) {
			if (ll(i) * p < 100001)
				rec[i * p] = 1;
			else break;
		}
	}
	int psize = prime.size();
	ll cur;
    //所有两异素数积是四因数数字
	for (int i = 0; i < psize ; i++)
		for (int j = i + 1; j < psize; j++) {
			cur = ll(prime[i]) * prime[j];
			if (cur <= 100001)
				rec[cur] = cur + 1 + prime[i] + prime[j];
			else
				break;
		}
    //所有素数三次方是四因数数字
	for (int i = 0; prime[i] < 100; i++)
		if (pow(prime[i],3) < 100001)
			rec[pow(prime[i],3)] = (pow( prime[i],4)-1)/ (prime[i] - 1);//直接记录为因数和
        else break;
	int sum = 0;
    //累加结果
	for (auto& n : nums)
		if (rec[n] > 1)//rec[i]为一时，i只是个普通的合数
			sum += rec[n];
	return sum;
}
};
