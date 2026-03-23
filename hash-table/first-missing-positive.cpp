class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        
        int n = nums.size();
        for(int i=0; i<n; i++){
            while(nums[i] >= 1 && nums[i] <=n && nums[i] != nums[nums[i]-1]){
                swap(nums[i], nums[nums[i]-1]);
            }
        }

        for(int i=0; i<n; i++){
            if(nums[i] != i+1){
                return i+1;
            }
        }
        return n+1;
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        // int n = nums.size();
        // for(int i=0; i<n; i++){
        //     //basically if the nums[i] != nums[nums[i]-1]
        //     //like if 1 is not at index 0 then swap
        //     //index 0 -> 1
        //     //index 1 -> 2 
        //     while(nums[i] >= 1 && nums[i] <=n && nums[nums[i]-1] != nums[i]){
        //         swap(nums[i], nums[nums[i] - 1]);
        //     }
        // }

        // for(int i=0; i<n; i++){
        //     if(nums[i] != i+1){
        //         return i+1;
        //     }
        // }
        // return n+1;
    }
};