class TimeMap {
public:
    unordered_map<string, vector<pair<int, string>>> timeMap;
    TimeMap() {
    }
    
    void set(string key, string value, int timestamp) {
        timeMap[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        auto it = upper_bound(
            timeMap[key].begin(), 
            timeMap[key].end(), 
            timestamp, [](int t, const pair<int, string&> p){
                return t < p.first;            
            });
        if(it == timeMap[key].begin()) return "";
        it--;
        return it->second;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */