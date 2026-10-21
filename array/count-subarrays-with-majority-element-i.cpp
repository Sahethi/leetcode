class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        //for the target to be the majority elelemt it should apper more than half times
        int count = 0;
        for(int i=0; i<nums.size(); i++){
            int score = 0;
            for(int j=i; j<nums.size(); j++){
                if(nums[j] == target){
                    score++;
                }else{
                    score--;
                }
                if(score > 0) count++;
            }
            
        }

        return count;
    }   
};