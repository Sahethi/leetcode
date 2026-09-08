class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        
        //this immediately screams binary search
        int left1 = 0, left2 = 0;
        int right1 = nums.size() - 1, right2 = nums.size()-1;
        int firstOcc = -1, lastOcc = -1;
        while(left1 <= right1 || left2 <= right2){

            if(left1 <= right1){
                int mid1 = left1 + (right1 - left1)/2;
                if(nums[mid1] == target){
                    //found it but we arent sure if this is the ultimate occurence 
                    firstOcc = mid1;
                    right1 = mid1 - 1;
                }else if(nums[mid1] < target){
                    left1 = mid1 + 1;
                }else{
                    right1 = mid1 - 1;
                }
            }
            
            if(left2 <= right2){
                int mid2 = left2 + (right2 - left2)/2;
                if(nums[mid2] == target){
                    //found it but we arent sure if this is the ultimate occurence 
                    lastOcc = mid2;
                    left2 = mid2 + 1;
                }else if(nums[mid2] < target){
                    left2 = mid2 + 1;
                }else{
                    right2 = mid2 - 1;
                }
            }
        }

        return {firstOcc, lastOcc};
    }
};