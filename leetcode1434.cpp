class Solution {
public:
    int numberWays(vector<vector<int>>& hats) {
    	int i, state, mod = 1e9+7, n = hats.size();//n个人
    	int N = (1<<n);//n个人带帽子或不戴帽子有2^n种可能(这个维度比较小n最大10)
    	vector<vector<long long>> dp(41,vector<long long>(N,0));
    	//dp[i][j]表示戴上第i个帽子后，人们戴帽子状态为 j(拆成二进制位0没戴，1戴了)的戴帽子方案数
    	//初始化
    	dp[0][0] = 1;//都没戴帽子1种情况
    	vector<set<int>> hat_p(41);//某个帽子可以戴的人
    	for(i = 0; i < n; ++i)
    		for(int hat : hats[i])
    			hat_p[hat].insert(i);
		for(i = 1; i <= 40; ++i)//遍历每个帽子
		{
            dp[i] = dp[i-1];//第i个帽子不戴
            //以下处理第i个帽子要戴的情况（前提那个人i-1时候没有戴帽子）
			for(int p : hat_p[i])//该帽子可以戴的人p
			{
				for(state = 0; state < N; ++state)//遍历所有可能的状态
				{
					if(((((state-(1<<p)))>>p)&1)==0)
					{   //到达state状态之前的状态是state-(1<<p)，该位为0，p号人没有戴帽子
						dp[i][state] += dp[i-1][state-(1<<p)];
					}	//所有i-1没戴帽子的，满足条件的，戴上i号帽子，加总
				}
			}
		}
		return dp[40][N-1]%mod;//N-1表示二进制111...11，都戴了帽子
    }
};