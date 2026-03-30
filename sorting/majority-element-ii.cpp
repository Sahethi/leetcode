class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int times = floor(n/3);
        unordered_set<int> res;

        unordered_map<int, int> count;
        for(int n : nums){
            count[n]++;
        }

        for(int n : nums){
            if(count[n] > times) res.insert(n);
        }

        return vector<int>(res.begin(), res.end());
    }
};