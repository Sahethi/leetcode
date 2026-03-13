class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        if(k<0) return 0;
        int ans = 0;
        unordered_map<int, int> freq;

        for(int n: nums){
            freq[n]++;
        }

        for(auto& [num, count] : freq){
            if(k == 0){
                if(count > 1)
                    ans++;
            }else{
                if(freq.count(num - k))
                    ans++;
            }
        }

        return ans;
    }
};