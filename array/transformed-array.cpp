class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n);

        //abs(-2) = 2 move it left size = 4 current index is 1 ---- 1 - 2 = -1 and 4 - 1 = 3
        //4 is at 0 move 4 to right if more than size then 4%size .. 4%4 = 0
        //
    
        for(int i=0; i<n; i++){
            result[i] = nums[((i + nums[i]) % n + n) % n];
        }

        return result;
    }
};