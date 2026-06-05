class Solution {
public:
    int countPrimes(int n) {
        vector<bool> isPrime(n, true);

        if (n <= 2) return 0;

        isPrime[0] = false;
        isPrime[1] = false;

        for (long long p = 2; p * p < n; p++) {
            if (isPrime[p]) {
                for (long long multiple = p * p; multiple < n; multiple += p) {
                    isPrime[multiple] = false;
                }
            }
        }

        int count = 0;
        for (int i = 2; i < n; i++) {
            if (isPrime[i]) {
                count++;
            }
        }

        return count;
    }
};