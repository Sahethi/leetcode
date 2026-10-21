class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> new_nums(2*n);

        /**
        [
        2,5,1,3,4,7]
        0 1 2 3 4 5
        0 3
        1 4
        2 5
        n = 3
        if  j = 0 
            j+1 = 0 + n = 0 + 3 = 3 
            j = 2
        */
        int j = 0;
        for(int i=0; i<n; i++){
            new_nums[j] = nums[i];
            new_nums[j+1] = nums[i+n];
            j+=2;
        }

        return new_nums;
    }
};