class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int hold = -prices[0];
        int notHold = 0;

        for(int i=1; i<prices.size(); i++){
            int prevHold = hold;
            int prevNotHold = notHold;

            hold = max(prevHold, prevNotHold - prices[i]);
            notHold = max(prevNotHold, prevHold + prices[i] - fee);
        }

        return notHold;
    }
};