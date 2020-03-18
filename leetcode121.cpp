class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int> pre(prices.size());
        int minn = 0x3f3f3f3f;
        for(int i =  1 ; i < prices.size() ; i++){
            minn = min(minn,prices[i-1]);
            pre[i] = minn;
        }
        int ans = 0;
        for(int i = 1 ; i < prices.size() ; i++){
            ans = max(ans,prices[i]-pre[i]);
        }
        return ans;
    }

};