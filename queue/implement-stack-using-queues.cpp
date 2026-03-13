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
            int front = queue1.front();
            queue1.pop();
            queue2.push(front);
        }
        int pop = queue1.front();
        queue1.pop();
        swap(queue1, queue2);
        return topEl;
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