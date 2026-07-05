class Solution {
public:
    long long minEnd(int n, int x) {
        // vector<long long> nums;

        // nums.push_back(x);
        // long long candidate = x + 1;

        // while(nums.size() < n){
        //     if((candidate & x) == x) {
        //         nums.push_back(candidate);
        //     }
        //     candidate++;
        // }

        // return nums[n-1];

        long long ans = x;
        long long k = n-1;
        for(int i=0; i<63; i++){

            if((((long long)x >> i) & 1) == 0){
                if(k & 1){
                    ans |= (1LL << i);
                }
                k >>= 1;
                if(k == 0) break;
            }
        }

        return ans;
    }
};