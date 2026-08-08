class Solution {
public:
    int smallestEvenMultiple(int n) {
        int ans = n * 2;
        if(n % 2 == 0) return n;
        return ans;
    }
};

