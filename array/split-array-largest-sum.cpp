class Solution {
    bool canSplit(vector<int>& nums, int k, int maxSum){

        int count = 1;
        int currSum = 0;

        for(int n : nums){
            if(currSum + n > maxSum){
                count++;
                currSum = n;
            }else{
                currSum += n;
            }
        }

        return count <= k;

    }
public:
    int splitArray(vector<int>& nums, int k) {
        int left = *max_element(nums.begin(), nums.end());
        //right will have the sum of all elements in the array
        int right = accumulate(nums.begin(), nums.end(), 0);

        int ans = right;

        while(left <= right){
            int mid = left + (right - left) / 2;

            if(canSplit(nums, k, mid)){
                ans = mid;
                right = mid - 1;
            }else{
                left = mid + 1;
            }
        }

        return ans;
    }
};