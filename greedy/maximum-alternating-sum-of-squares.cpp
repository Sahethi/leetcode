class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        vector<int> sortedSquared;

        for(int n : nums){
            sortedSquared.push_back(n*n);
        }
        sort(sortedSquared.begin(), sortedSquared.end());

        int n = sortedSquared.size();
        int left = 0;
        int right = n-1;

        long long result = 0;

        while(left < right){
            result += sortedSquared[right--] - sortedSquared[left++];
        }

        if(left == right){
            result += sortedSquared[left];
        }

        return result;
    }
};