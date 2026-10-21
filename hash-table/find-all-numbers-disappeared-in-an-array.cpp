class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        
        vector<int> res;
        int n = nums.size();
        for(int i=0; i<n; i++){
            int idx = abs(nums[i]) - 1;
            if(nums[idx] > 0)
                nums[idx] = -nums[idx];
        }

        for(int i=0; i<n; i++){
            if(nums[i] > 0){
                res.push_back(i+1);
            }
        }

        return res;
        /**
        vector<int> res;
        int n = nums.size();
        
        //[4,3,2,7,8,2,3,1]
        //[1,2,2,3,3,4,7,8]
        unordered_map<int, int> freq;

        for(int n : nums){
            freq[n]++;
        }
        
        for(int i=1; i<=n; i++){
            if(freq[i] == 0) res.push_back(i);
        }

        return res;
        **/
    }
};