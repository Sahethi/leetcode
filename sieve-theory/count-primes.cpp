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
        vector<bool> isPrime(n,true);
        isPrime[0] = false;
        isPrime[1] = false;
    
        for(long long i=2; i*i < n; i++){
            if(isPrime[i]){
                for(long long multiple=i*i; multiple < n; multiple += i){
                    isPrime[multiple] = false;
                }
            }
        }

        for(int i=2; i<n; i++){
            if(isPrime[i]) count++;
        }

        return count;
    }
    
};
