
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        if (n < 3) return 0;

        int left = 0, ans = 0;
        // 1 2 3 4
        for(int right = 2; right < n; right++){
            if(nums[right] - nums[right-1] != nums[right-1] - nums[right-2]){
                left = right - 1;
            }
            int len = right - left + 1;
            ans += len - 2;
        }

        return ans;
    }
};
