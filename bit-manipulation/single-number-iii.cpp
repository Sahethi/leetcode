class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        
        unordered_map<int, int> freq;

        for(int n : nums){
            freq[n]++;
        }

        vector<int> res;

        for(auto &[n, count] : freq){
            if(count == 1){
                res.push_back(n);
            }
        }

        return res;
    }
};