class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        
        //some dead giveaways for binary search is sorted array and complexity (log n)

        int low = 0, high = nums.size()-1;
        while(low < high){
            int mid = low + (high - low)/2;
            
            //keep mid even
            if(mid % 2 == 1){
                mid--;
            }

            if(nums[mid] == nums[mid+1]){
                low = mid + 2;
            }else{
                high = mid; // here the pattern is broken
            }
        } 
        
        return nums[low];

        /**
        //the solution i gave below is O(n)
        //one would have to do binary search to get O(log n)
        int n = nums.size();
        if(n == 1) return nums[0];

        for(int i=0; i<n; i++){
            if(i != 0 && i != n-1){
                if(nums[i-1] != nums[i] && nums[i+1] != nums[i]){
                    return nums[i];
                }
            }else if(i==0){
                if(nums[i+1] != nums[i]) return nums[i];
            }else if(i==n-1){
                if(nums[i-1] != nums[i]) return nums[i];
            }
        }

        return 0;
        **/
    }
};