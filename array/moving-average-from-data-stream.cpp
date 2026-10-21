class MovingAverage {
public:
    int n;
    queue<int> q;
    double sum;
    MovingAverage(int size) {
        n = size;
        sum = 0;
    }
    
    double next(int val) {
        q.push(val);

        sum += val;

        int size = q.size();

        if(q.size() > n){
            size = n;
            sum = sum - q.front();
            q.pop();
        }else{
            size = q.size();
        }

        return sum/size;
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */