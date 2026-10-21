class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int left, right;
        sort(nums.begin(), nums.end());
        int closestSum = nums[0] + nums[1] + nums[2];
        int minDiff = abs(closestSum - target);
        for(int i=0; i<nums.size(); i++){
            left = i+1;
            right = nums.size()-1;

            while(left < right){
                int sum = nums[i] + nums[left] + nums[right];
                int diff = abs(sum - target);
                if(diff < minDiff){
                    minDiff = diff;
                    closestSum = sum; 
                }
                if(sum < target){
                    left++;
                }else if(sum > target){
                    right--;
                }else{
                    return sum;
                }
            }
        }

        return closestSum;
    }
};