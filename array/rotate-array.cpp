class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        //another approach would be with reversing the array 
        //1,2,3,4,5,6,7
        //k = 3
        //7,6,5,4,3,2,1
        //reverse first k elemenrs 5,6,7 then reverse remaining 1,2,3,4
        
        int n = nums.size();
        k = k % n;
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin()+k);
        reverse(nums.begin()+k, nums.end());
        

        /**
        int n = nums.size();
        vector<int> temp(n);
        for(int i=0; i<n; i++){
            //rotates the index right
            //for left rotation is (i-k+n) % n
            int new_index = (i + k) % n;
            temp[new_index] = nums[i];
        }
        nums = temp;
        **/
    }
};