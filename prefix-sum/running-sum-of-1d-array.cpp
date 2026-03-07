class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int> res;
        int total = 0;
        for(int n: nums){
            total += n;
            res.push_back(total);
        }
        return res;
    }
};