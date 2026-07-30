class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count = 0;
        int maxDist = 0;

        if(nums.size() == 1){
            if(nums[0] == 1) return 1;
            else return 0;
        }

        for(int i=0; i<nums.size(); i++){
            if(nums[i] == 1) count++;
            else count = 0;
            maxDist = max(maxDist, count);
        }

        return maxDist;
    }
};