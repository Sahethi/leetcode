class Solution {
private:
    void backtrack(int start, vector<vector<int>>& result, vector<int>& current, vector<int>& nums){
        
        result.push_back(current);

        for(int i=start; i<nums.size(); i++){
            if(i > start && nums[i] == nums[i-1]) continue;

            current.push_back(nums[i]);
            backtrack(i+1, result, current, nums);
            current.pop_back();
        }   
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        vector<int> current;

        backtrack(0, result, current, nums);

        return result;
    }
};