class Solution {
public:
    int arrangeCoins(int n) {
        //n coin with coins u need to build staircase
        //then staircase contins k rows where ith row has exactly i coins
        //last row can be incomplete
        //return number of complete rows

        //n = 5 ... 1 2 3 4 5 6 

        //im thinking of calculate gaps 
        // 1 + 2 + 3 + k ... triangular numbers k (k+1) / 2 
        // but we are given n coins
        // k (k+1) / 2 <= n
        // k(k+1) <= 2n
        //this is like a qudratic equation

        // long long k = (sqrt(1 + 8LL * n) - 1) / 2;

        // return (int)k;

        int left = 1, right = n;

        while(left <= right){
            long long mid = left + (right - left)/2;
            long long currCoins = mid * (mid + 1) / 2;

            if(currCoins > n){
                right = mid - 1;
            }else if (currCoins < n){
                left = mid + 1;
            }else{
                return mid;
            }
        }
        return right;
    }
};