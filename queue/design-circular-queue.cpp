class MyCircularQueue {
public:
    int head, tail, size, capacity;
    vector<int> data;
    MyCircularQueue(int k) {
        head = -1;
        tail = -1;
        size = 0;
        capacity = k;
        data.resize(k);
    }
    
    bool enQueue(int value) {
        if(isFull()) return false;
        if(isEmpty()){
            head = 0;
            tail = 0;
        }else{
            tail = (tail + 1) % capacity;
        }
        data[tail] = value;
        size++;
        return true;
    }
    
    bool deQueue() {
        //think about what happens in deQueue
        //if the queue is already empty then u cant dequeue it further 

        if(isEmpty()) return false;
        //now if the queue does have elements check if the head is in the end
        // if the head is the in end then it needs to wrapped around right
        // head = (head + 1) % capacity;
        //data[head] needs to get emptied out
        //size--;
        //return true? 

        if(head == tail){
            head = -1;
            tail = -1;
        }else{
            head = (head + 1) % capacity;
        }
        size--;
        return true;
    }
    
    int Front() {
        if(isEmpty()) return -1;
        return data[head];
    }
    
    int Rear() {
        if(isEmpty()) return -1;
        return data[tail];
    }
    
    bool isEmpty() {
        if(size == 0) return true;
        return false;
    }   
    
    bool isFull() {
        if(size == capacity) return true;
        return false;
    }   
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */