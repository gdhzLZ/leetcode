class Solution(object):
    def coinChange(self, coins, amount):
        """
        :type coins: List[int]
        :type amount: int
        :rtype: int
        """
        if amount == 0:
            return 0
        dp = [0x3f3f3f for _ in range(amount+1)]
        dp[0] = 0
        minn = 0x3f3f3f
        for i in range(len(coins)):
            for j in range(1,amount+1):
                if coins[i] > j :
                    continue;
                dp[j] = min(dp[j],dp[j-coins[i]]+1)
              
                if j == amount:
                    minn = min(dp[j],minn)
       
        if minn == 0x3f3f3f:
            return -1
        else :
            return minn