class StockSpanner {
public:
    vector<int> stockPrice;
    StockSpanner() {
        
    }
    
    int next(int price) {
        stockPrice.push_back(price);
        int span = 1;
        if(stockPrice.size() == 1) return 1;

        for(int i=stockPrice.size()-2; i>=0; i--){
            if(stockPrice[i] > price){
                break;
            }else{
                span++;
            }
        }
        return span;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */