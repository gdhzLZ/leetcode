class Solution(object):
    def findMaxForm(self, strs, m, n):
        """
        :type strs: List[str]
        :type m: int
        :type n: int
        :rtype: int
        """
        dp = [[0 for _ in range(n+1)] for __ in range(m+1)]
        maxx = -0x3f3f3f3f
        for w in range(len(strs)):
            num0 = strs[w].count('0')
            num1 = strs[w].count('1')
            for i in range(m,-1,-1):
                for j in range(n,-1,-1): 
                    if i < num0 or j < num1:
                        continue
                    dp[i][j] = max(dp[i][j],dp[i-num0][j-num1]+1)
                    maxx = max(maxx,dp[i][j])
        if maxx == -0x3f3f3f3f:
            return 0
        return maxx