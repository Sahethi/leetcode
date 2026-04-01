class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        
        int orOfAll = 0;
        for(int num : nums){
            orOfAll |= num;
        }

        int multiplier = 1 << (nums.size()-1);

        return orOfAll * multiplier;
    }
};