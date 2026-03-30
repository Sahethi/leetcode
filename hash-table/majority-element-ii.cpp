class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int times = floor(n/3);
        vector<int> res;

        unordered_set<int> unique_nums;

        for(int n : nums){
            unique_nums.insert(n);
        }

        unordered_map<int, int> count;
        for(int n : nums){
            count[n]++;
        }

        for(int n : unique_nums){
            if(count[n] > times) res.push_back(n);
        }

        return res;
    }
};