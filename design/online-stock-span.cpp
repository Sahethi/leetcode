class StockSpanner {
public:
    stack<int> stockPrice;
    StockSpanner() {
        
    }
    
    /**
    if incoming price is 
    **/
    int next(int price) {
        if(stockPrice.empty()){
            stockPrice.push(price);
        } else {
            if(stockPrice.top() > price){
                while(!stockPrice.empty()){
                    stockPrice.pop();
                }
                stockPrice.push(price);
            }else{
                stockPrice.push(price);
            }
        }
        
        
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
        return stockPrice.size();
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */