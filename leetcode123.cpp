class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() == 0) return 0;
        int ans = 0;
        int hold[2] ,nothold[3];
        nothold[0] = 0,nothold[1] = -0x3f3f3f3f;
        hold[0] = -prices[0],hold[1] = -0x3f3f3f3f;
        nothold[2] = 0;
        for(int i = 1 ; i < prices.size() ; i++){
            int temp = nothold[1];
            int temp2 = hold[1];
            nothold[1] =max(nothold[1],hold[0]+prices[i]);
            hold[1] = max(hold[1],nothold[1]-prices[i]);
            hold[0] = max(hold[0],nothold[0]-prices[i]);
            nothold[0] = 0;
            nothold[2] = max(nothold[2],temp2+prices[i]);
            ans = max(ans,max(nothold[1],nothold[2]));
        }
        return ans;
    }
};