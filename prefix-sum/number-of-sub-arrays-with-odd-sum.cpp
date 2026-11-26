class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        // long long odd = ranges::count_if(arr, [sum = 0](int x) mutable { return (sum += x) & 1; });  // odd prefix sums
        // long long even = arr.size() + 1 - odd;  // the empty prefix is even
        // return odd * even % 1'000'000'007;

        const int MOD = 1e9 + 7;

        long long result = 0;
        int prefixSum = 0;
        int evenCount = 1;
        int oddCount = 0;

        for(int n : arr){
            prefixSum += n;

            //current prefixSum is even
            if(prefixSum % 2 == 0){
                result += oddCount;
                evenCount++;
            }else{
                result += evenCount;
                oddCount++;
            }

            result %= MOD;
        }

        return result;
    }
};