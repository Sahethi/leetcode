class MyHashSet {
public:
    //hash function is key % size
    int size; // using prime seperates the buckets more evenly
    vector<vector<int>> buckets;
    MyHashSet() {
        size = 769;
        buckets.resize(size);
    }   
    
    void add(int key) {
        int index = key % size;

        for(int num : buckets[index])
            if(num == key) return;

        buckets[index].push_back(key);
    }
    
    void remove(int key) {
        int index = key % size;
        for(int i = 0; i<buckets[index].size(); i++){
            if(buckets[index][i] == key){
                int temp = buckets[index].back();
                buckets[index][i] = temp;
                buckets[index].pop_back();
                return;
            }
        }
    }
    
    bool contains(int key) {
        int index = key % size;

        for(int num : buckets[index]){
            if(num == key) return true;
        }
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */