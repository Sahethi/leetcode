class DataStream {
public:
    vector<int> elements;
    int size, data;
    int count = 0;
    DataStream(int value, int k) {
        data = value;
        size = k;
    }
    
    bool consec(int num) {
        if(num == data) count++;
        else count = 0;

        return count >= size;
    }
};

/**
 * Your DataStream object will be instantiated and called as such:
 * DataStream* obj = new DataStream(value, k);
 * bool param_1 = obj->consec(num);
 */