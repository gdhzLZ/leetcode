class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
       int nothold = 0,hold = -prices[0];
       for(int i = 1 ; i < prices.size() ; i++){
           int temp = hold;
           hold = max(hold,nothold-prices[i]);
           nothold = max(nothold,temp+prices[i]-fee);
       }
       return nothold;
    }
}; 