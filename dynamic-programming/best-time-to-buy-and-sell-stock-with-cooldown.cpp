class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int hold = -prices[0];
        int rest = 0;
        int sold = 0;
        for(int i=1; i<prices.size(); i++){
            int prevHold = hold;
            int prevRest = rest;
            int prevSold = sold;

            hold = max(prevHold, prevRest - prices[i]);
            sold = prevHold + prices[i];
            rest = max(prevRest, prevSold);
        }

        return max(sold, rest);
    }
};