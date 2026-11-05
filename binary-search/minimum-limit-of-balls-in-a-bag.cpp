class Solution {
private:
    bool canSplit(vector<int>& nums, int maxOps, int target){
        //check interger division in koko eats banana
        long long ops = 0;
        for(int n : nums){
            ops += (n - 1)/target;
        }

        return (ops <= maxOps);
    }
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        /**
        so we try different targets and check if its within our range of maxops
        */
        int left = 1;
        int right = *max_element(nums.begin(), nums.end());

        while(left < right){
            int mid = left + (right - left) / 2;

            if(canSplit(nums, maxOperations, mid)){
                right = mid; 
            }else{
                left = mid + 1;
            }
        }

        return left;
    }
};