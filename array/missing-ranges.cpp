class Solution {
public:
    vector<vector<int>> findMissingRanges(vector<int>& nums, int lower, int upper) {
        // if(lower == upper) return {};
        vector<vector<int>> res;
        int prev = lower - 1;
        for(int i=0; i<nums.size(); i++){
            if(prev + 1 > nums[i] - 1){
                prev = nums[i];
                continue;
            }else{
                res.push_back({prev + 1 , nums[i] - 1}); 
                prev = nums[i];
            }
        }

        if(prev+1 <= upper)
            res.push_back({prev + 1 , upper});

        return res;
    }
};