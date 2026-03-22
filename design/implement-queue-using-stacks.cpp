class MyQueue {
public:
    stack<int> pushStack;
    stack<int> popStack;

    MyQueue() {
        
    }
    
    void push(int x) {
        pushStack.push(x);
    }
    
    int pop() {
        if (popStack.empty()) {
            while(!pushStack.empty()){
                int topEl = pushStack.top();
                pushStack.pop();
                popStack.push(topEl);
            }
        }
        int remove = popStack.top();
        popStack.pop();
        return remove;
    }
    
    int peek() {
        if (popStack.empty()) {
            while(!pushStack.empty()){
                int topEl = pushStack.top();
                pushStack.pop();
                popStack.push(topEl);
            }
        }
        int peeked = popStack.top();
        return peeked;
    }
    
    bool empty() {
        return pushStack.empty() && popStack.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */