class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int>nothold(prices.size());
        vector<int>hold(prices.size());
        if(prices.size() == 0 || prices.size() == 1) return 0;
        if(prices.size() == 2)return max(0,prices[1]-prices[0]);
        int maxNothold;
        int maxhold;
        hold[0] = -prices[0];nothold[0] = 0;hold[1] = -prices[1];nothold[1] =(prices[1]-prices[0]);
        maxhold = max(hold[0],hold[1]);
        maxNothold=nothold[0];
        for(int i = 2  ;i < prices.size() ; i++){
            int tempnothold = maxhold+prices[i];
            int temphold = maxNothold-prices[i];
            hold[i] = temphold;
            nothold[i] =tempnothold;
            maxNothold=max(maxNothold,nothold[i-1]);
            maxhold=max(maxhold,hold[i]);
        }
        return max(maxNothold,nothold[prices.size()-1]);
    }
};