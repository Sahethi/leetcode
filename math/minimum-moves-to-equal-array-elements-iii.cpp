class Solution {
public:
    int minMoves(vector<int>& nums) {
        /**
        If you are only allowed to increase, then I think all the elements need to match the max element, so we would have to sum the difference, if I'm not wrong. 
        */

        int maxEl = *max_element(nums.begin(), nums.end());

        int minMoves = 0;

        for(int n :nums){
            minMoves += (maxEl-n);
        }

        return minMoves;
    }
};