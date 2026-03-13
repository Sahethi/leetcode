class MyStack {
public:
    queue<int> queue1;
    queue<int> queue2;
    int topEl;
    MyStack() {
        
    }
    
    void push(int x) {
      queue1.push(x);  
      topEl = x;
    }
    
    int pop() {
        while(queue1.size() > 1){
            topEl = queue1.front();
            
            queue2.push(queue1.front());
            queue1.pop();
        }
        int pop = queue1.front();
        queue1.pop();
        swap(queue1, queue2);
        return pop;
    }
    
    int top() {
        return topEl;
    }
    
    bool empty() {
        if(queue1.empty() && queue2.empty()) return true;
        return false;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */