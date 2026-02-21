class Solution {
public:
    vector<int> prefix;
    int total;
    Solution(vector<int>& w) {
        total = 0;
        for (int weight : w) {
            total += weight;
            prefix.push_back(total);
        }
    }
    
    int pickIndex() {
        //will generate a random number between 1 - max index
        int r = rand() % total + 1;
        //the function lower_bound tried to find the first postion of x wihtout breaking the sorted order
        //it returns a iterator
        //we want to find the index from start hence - prefix.begin()
        return lower_bound(prefix.begin(), prefix.end(), r) - prefix.begin();
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */