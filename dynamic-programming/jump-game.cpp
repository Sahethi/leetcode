class Solution {
public:
    bool canJump(vector<int>& nums) {
        
        //greedy
        int maxJump = 0;
        for(int i=0; i<nums.size(); i++){
            //basically index is more than maxJump
            if(i > maxJump) return false;

            maxJump = max(maxJump, i + nums[i]);

            // if(maxJump >= nums.size()-1) return true;
        }

        return true;
    }
};