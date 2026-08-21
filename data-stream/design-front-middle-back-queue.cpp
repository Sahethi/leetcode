class FrontMiddleBackQueue {
private:
    deque<int> left, right;
public:
    FrontMiddleBackQueue() {
        
    }
    
    void pushFront(int val) {
        left.push_front(val);
        if(left.size() > right.size()+1){
            int el = left.back();
            left.pop_back();
            right.push_front(el);
        }
    }
    
    void pushMiddle(int val) {
        if(left.size() > right.size()){
            int el = left.back();
            left.pop_back();
            left.push_back(val);
            right.push_front(el);
        }else{
            left.push_back(val);
        }
    }
    
    void pushBack(int val) {
        right.push_back(val);
        if(right.size() > left.size()+1){
            int el = right.front();
            right.pop_front();
            left.push_back(el);
        }
    }
    
    int popFront() {
        if(left.empty() && right.empty()) return -1;

        if(!left.empty()){
            int el = left.front();
            left.pop_front();
            if(right.size() > left.size()+1){
                int itm = right.front();
                right.pop_front();
                left.push_back(itm);
            }
            return el;
        }else{
            int el = right.front();
            right.pop_front();
            return el;
        }
    }
    
    int popMiddle() {
        if(left.empty() && right.empty()) return -1;

        int el;
        if(right.size() > left.size()){
            el = right.front();
            right.pop_front();
        }else{
            el = left.back();
            left.pop_back();
        }
        return el;
    }
    
    int popBack() {
        if(left.empty() && right.empty()) return -1;

        if(!right.empty()){
            int el = right.back();
            right.pop_back();
            if(left.size() > right.size()+1){
                int itm = left.back();
                right.push_front(itm);
                left.pop_back();
            }
            return el;
        }else{
            int el = left.back();
            left.pop_back();
            return el;
        }
    }
};

/**
 * Your FrontMiddleBackQueue object will be instantiated and called as such:
 * FrontMiddleBackQueue* obj = new FrontMiddleBackQueue();
 * obj->pushFront(val);
 * obj->pushMiddle(val);
 * obj->pushBack(val);
 * int param_4 = obj->popFront();
 * int param_5 = obj->popMiddle();
 * int param_6 = obj->popBack();
 */