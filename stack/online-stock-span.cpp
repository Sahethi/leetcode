class StockSpanner {
public:
    stack<pair<int, int>> stockPrice;
    StockSpanner() {
        
    }
    
    /**
    if incoming price is 
    **/
    int next(int price) {
        int span = 1;
        while(!stockPrice.empty() && stockPrice.top().first <= price){
            span += stockPrice.top().second;
            stockPrice.pop();
        }

        stockPrice.push({price, span});
        return span;
        
        // stockPrice.push_back(price);
        // int span = 1;
        // if(stockPrice.size() == 1) return 1;

        // for(int i=stockPrice.size()-2; i>=0; i--){
        //     if(stockPrice[i] > price){
        //         break;
        //     }else{
        //         span++;
        //     }
        // }
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */