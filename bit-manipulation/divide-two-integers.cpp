class Solution {
public:
    long long multiply(long long a, long long b){
        long long result = 0;

        while(b > 0){

            if(b & 1){
                result += a;
            }

            a = a << 1; // you gotta move it forward and double it 
            b = b >> 1; // reduce the bits for the b
        }

        return result;
    }

    int divide(int dividend, int divisor) {
        //i can also think of binary search approach for this
        /**

        where we have the answer between 0 and the dividend

        so like dividend / divisor = ans
        dividend = ans * divisor 

        ans * divisor <= dividend ... but we arent supposed to use mutliplication

        but here the ans can be mid

        if answer is less than dividend
        then move right - we need to increase our mid right to make it match to our dividend

        else move left
        **/

        if(dividend == INT_MIN && divisor == -1){
            return INT_MAX;
        }

        

        bool negative = (dividend < 0) ^ (divisor < 0);

        long long dvd = llabs((long long)dividend);
        long long dvs = llabs((long long)divisor);

        long long left = 0;
        long long right = dvd;
        long long ans = 0;

        while(left <= right){
            long long mid = left + (right - left)/2;

            if(multiply(mid, dvs) <= dvd){
                ans = mid;
                left = mid + 1;
            }else{
                right = mid - 1;
            }
        }

        if(negative)
            ans = -ans;

        return ans;
        // /**
        // we check this 
        // INT_MIN = -2147483648
        // and if divisor is -1
        // and this can result in 2147483648
        // **/

        // if (dividend == INT_MIN && divisor == -1)
        //     return INT_MAX;

        // //same hai to 0 diff hai toh 1
        // bool negative = (dividend < 0) ^ (divisor < 0);

        // long long dvd = llabs((long long)dividend);
        // long long dvs = llabs((long long)divisor);

        // long long ans = 0;

        // while(dvd >= dvs){
        //     long long temp = dvs;
        //     long long multiple = 1;

        //     while((temp << 1) <= dvd){
        //         temp <<= 1;
        //         multiple <<= 1;
        //     }

        //     dvd -= temp;
        //     ans += multiple;
        // }

        // if(negative)
        //     ans = -ans;
        

        // return (int)ans;

    }
};