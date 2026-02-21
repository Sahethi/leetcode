class LFUCache {
    int cap;
    int minFreq;

    //key -> {value, frequency}
    unordered_map<int, pair<int, int>> keyVal;
    //freq -> list of keys (most recent in the front and least in the back)
    unordered_map<int, list<int>> freqList;
    //key -> iterator to get exact pos in the freqList
    unordered_map<int, list<int>::iterator> pos;
public:
    LFUCache(int capacity) {
        cap = capacity;
        minFreq = 0;
    }
    
    int get(int key) {
        if(keyVal.find(key) == keyVal.end()) return -1;

        updateFrequency(key);
        return keyVal[key].first;
    }

    void updateFrequency(int key){
        int curFreq = keyVal[key].second;

        freqList[curFreq].erase(pos[key]);

        keyVal[key].second++;
        int nextFreq = curFreq + 1;

        freqList[nextFreq].push_front(key);
        pos[key] = freqList[nextFreq].begin();

        if(freqList[minFreq].empty()){
            minFreq++;
        }
    }
    
    void put(int key, int value) {
        if(cap <= 0) return;

        if(get(key) != -1){
            keyVal[key].first = value;
            return;
        }

        if(keyVal.size() >= cap){
            int evict = freqList[minFreq].back();

            keyVal.erase(evict);
            pos.erase(evict);
            freqList[minFreq].pop_back();
        }

        keyVal[key] = {value, 1};
        freqList[1].push_front(key);
        pos[key] = freqList[1].begin();
        minFreq = 1;
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */