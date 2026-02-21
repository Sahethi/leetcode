class Solution {
public:
    int jump(vector<int>& nums) {
        int jumps = 0;
        int maxJump = 0;
        int currentMax = 0;

        for(int i=0; i<nums.size()-1; i++){
            maxJump = max(maxJump, i + nums[i]);
            if(i == currentMax){
                jumps++;
                currentMax = maxJump;
            }
        }

        return jumps;
    }
};