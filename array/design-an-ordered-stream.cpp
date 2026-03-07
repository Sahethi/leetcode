class OrderedStream {
public:
    vector<string> res;
    int ptr;
    OrderedStream(int n) {
        res.resize(n+1);
        ptr = 1;
    }
    
    vector<string> insert(int idKey, string value) {
        res[idKey] = value;
        vector<string> ans;
        while(ptr < res.size() && res[ptr] !=""){
            ans.push_back(res[ptr]);
            ptr++;
        }
        return ans;
    }
};

/**
 * Your OrderedStream object will be instantiated and called as such:
 * OrderedStream* obj = new OrderedStream(n);
 * vector<string> param_1 = obj->insert(idKey,value);
 */