class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy = prices[0];
        int profit = 0;

        for(int i=0; i<prices.size(); i++){

            //find the the day when the price is lowest, u buy on that day
            if(prices[i] < buy){
                buy = prices[i];
            } else if (prices[i] - buy > profit) {
                profit = prices[i] - buy;
            }
            //here what price we bought we will find diff with each element
            //in our prices vector, store the max profit, if we didint find anythign it will be 0 by default
        }

        return profit;
    }
};