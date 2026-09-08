class Solution {
public:
    // bool isPrime(int n){
    //     if(n<=1) return false;
    //     for(int i = 2; i * i <= n; i++)
    //         if(n%i == 0) return false;
    //     return true;

    // }
    int countPrimes(int n) {
        if(n <= 2) return 0;
        int count = 0;
        vector<bool> isPrime(n, true);
        isPrime[0] = false;
        isPrime[1] = false;
        //since i know im a prime, im going to go ahead and mark all my multiples
        //as not prime

        for(int i=2; i*i<n; i++){
            if(isPrime[i]){
                for(int j=i*i; j<n; j+=i){
                    isPrime[j] = false;
                }
            }
        }

        for(int i=2; i<n; i++){
            if(isPrime[i]) count++;
        }
        return count;
    }
};