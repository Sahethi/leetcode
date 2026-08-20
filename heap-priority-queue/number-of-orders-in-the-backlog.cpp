class Solution {
public:
    int getNumberOfBacklogOrders(vector<vector<int>>& orders) {
        //price, quantity, orderType
        //0 is buy and 1 is sell

        //[7, 3, 1]
        //sell 3 units at 7 per unit dollars 

        /**
        buy: 10
        sell: 7 
        sell <= buy
        7 <= 10 match

        buy: 6
        sell: 7
        7 <= 6 doesnt match

        sell would need a minheap 
        buy would need a maxheap
        **/

        priority_queue<pair<int,int>> buyOrders; // maxHeap
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> sellOrders; //minHeap

        for(auto &order : orders){
            if(order[2] == 0){
                //buy
                while(!sellOrders.empty() && sellOrders.top().first <= order[0] && order[1] > 0){
                    auto [sellPrice, sellQty] = sellOrders.top();
                    sellOrders.pop();

                    int traded = min(order[1], sellQty);
                    order[1] -= traded;
                    sellQty -= traded;
                    
                    if(sellQty > 0){
                        sellOrders.push({sellPrice, sellQty});
                    }
                }
                if(order[1] > 0){
                    buyOrders.push({order[0], order[1]});
                }
            }else{
                //sell
                while(!buyOrders.empty() && buyOrders.top().first >= order[0] && order[1] > 0){
                    auto [buyPrice, buyQty] = buyOrders.top();
                    buyOrders.pop();
                    
                    int traded = min(order[1], buyQty);
                    buyQty -= traded;
                    order[1] -= traded;

                    if(buyQty > 0){
                        buyOrders.push({buyPrice, buyQty});
                    }
                }
                if(order[1] > 0){
                    sellOrders.push({order[0], order[1]});
                }
            }
        }

        
        long long sum = 0;
        while (!buyOrders.empty()) {
            auto order = buyOrders.top();
            sum += order.second;
            buyOrders.pop();
        }
        
        while(!sellOrders.empty()){
            auto order = sellOrders.top();
            sum += order.second;
            sellOrders.pop();
        }

        return sum % 1000000007;
    }
};