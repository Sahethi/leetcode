class Solution {
public:
    long long minEnd(int n, int x) {
        vector<long long> nums;

        nums.push_back(x);
        long long candidate = x + 1;

        while(nums.size() < n){
            if((candidate & x) == x) {
                nums.push_back(candidate);
            }
            candidate++;
        }

        return nums[n-1];
    }
};