class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        
        int length = 1;
        int maxLen = 1;
        for(int i=0; i<nums.size()-1; i++){
            if(nums[i] < nums[i+1]){
                length++;
            }else{
                length = 1;
            }
            maxLen = max(length, maxLen);
        }

        return maxLen;
    }
};