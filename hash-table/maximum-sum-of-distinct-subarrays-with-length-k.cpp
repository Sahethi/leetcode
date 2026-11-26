class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        
        long long maxSum = 0;
        long long currentSum = 0;
        int left = 0;
        unordered_map<int, int> freq;
        for(int right = 0; right<nums.size(); right++){
            
            currentSum += nums[right];
            freq[nums[right]]++;

            if(right - left + 1 > k){
                currentSum = currentSum - nums[left];
                if(freq.find(nums[left]) != freq.end()){
                    freq[nums[left]]--;
                    if(freq[nums[left]] == 0){
                        freq.erase(nums[left]);
                    }
                }
                left++;
            }

            if(right - left + 1 == k && freq.size() == k){
                maxSum = max(maxSum, currentSum);
            }

        }

        return maxSum;
    }
};