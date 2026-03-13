class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        
        int ans =0;
        unordered_map<int, int> count;

        for(int i=0; i<nums.size(); i++){
            int n = nums[i] - k;
            for(int j=i+1; j<nums.size(); j++){
                if(n == nums[j]){
                    count[n]++;
                }
            }
            for(int j=0; j<i; j++){
                if(n == nums[j]){
                    count[n]++;
                }
            }
        }
        for(int i=0; i<count.size(); i++){
            ans++;
        }

        return ans;
    }
};