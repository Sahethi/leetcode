class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
    
        vector<string> result;
        int i=0;
        while(i<nums.size()){
            int start = i;
            int j = i;

            while(j < nums.size()-1 && nums[j+1] == nums[j]+1){
                j++;
            }

            if(nums[j] == nums[start]){
                result.push_back(to_string(nums[start]));
            }else{
                result.push_back(to_string(nums[start]) + "->" + to_string(nums[j]));
            }

            i = j+1;

        }

        return result;
    }
};