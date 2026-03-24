class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        int sum = 0;

        for(int i=0; i<nums.size(); i++){

            if(i>0 && nums[i] == nums[i-1]) continue; 

            int left = i + 1;
            int right = nums.size()-1;

            while(left < right){
                sum = nums[left] + nums[right] + nums[i];
                if(sum < 0) left++;
                else if(sum > 0) right--;
                else {
                    res.push_back({nums[left], nums[right], nums[i]});
                    right--;
                    left++;

                    //left has duplicate
                    while(left < right && nums[left] == nums[left-1])
                        left++;
                }
            }
        }   

        return res;
    }
};