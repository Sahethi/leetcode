class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
    
        int ans = 0;

        //xor result of two unique1 ^ unique2 are left
        for(int n : nums){
            ans ^= n;
        }

        int mask = ans & (-ans);

        int a=0, b=0;

        for(int n : nums){
            if(n & mask){
                a ^= n;
            }else{
                b ^= n;
            }
        }

        return {a, b};


        // unordered_map<int, int> freq;

        // for(int n : nums){
        //     freq[n]++;
        // }

        // vector<int> res;

        // for(auto &[n, count] : freq){
        //     if(count == 1){
        //         res.push_back(n);
        //     }
        // }

        // return res;
    }
};