class Solution {
public:
    long long getCost(vector<int>& nums, vector<int>& cost, long long target){
        long long totalCost = 0;
        for(int i=0; i<nums.size(); i++){
            totalCost += abs(nums[i] - target) * cost[i];
        }
        return totalCost;
    }
    long long minCost(vector<int>& nums, vector<int>& cost) {
        long long left = *min_element(nums.begin(), nums.end());
        long long right = *max_element(nums.begin(), nums.end());

        while(left < right){
            long long mid = left + (right - left)/2;

            if(getCost(nums, cost, mid) > getCost(nums, cost, mid+1)){
                left = mid + 1;
            }else{
                right = mid;
            }
        }

        return getCost(nums, cost, left);
    }
};