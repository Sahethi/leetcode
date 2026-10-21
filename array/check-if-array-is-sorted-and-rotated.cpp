class Solution {
public:
    bool check(vector<int>& nums) {
        //if the array is rotated
        //it will either be all ascendign order 
        //or it will be ascending...ascending
        // it wont be decsebcing and then ascending

        int breakpoint = 0;
        int n = nums.size();
        for(int i=0; i<n; i++){
            if(nums[i] > nums[(i + 1) % n]) breakpoint++;
        }

        if(breakpoint <= 1 ) return true;
        return false;
    }
};