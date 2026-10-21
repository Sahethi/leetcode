class Solution {
public:
    bool isPrime(int n){
        if(n <= 1) return false;
        for(int i=2; i*i<=n; i++){
            if(n % i == 0) return false;
        }
        return true;
    }
    vector<int> closestPrimes(int left, int right) {

        vector<int> ans = {-1, -1};
        int firstPrime = -1;
        int secondPrime = -1;
        int minDiff = INT_MAX;
        int prevPrime = -1;

        for(int i=left; i<=right; i++){
            if(isPrime(i)){
                if(prevPrime != -1){
                    int diff = i - prevPrime;

                    if(diff < minDiff){
                        minDiff = diff;
                        ans = {prevPrime, i};

                        if(minDiff <= 2) return ans;
                    }
                }
                prevPrime = i;
            }
        }

        return ans;
    }
};

