class Solution {
public:
    int divide(int dividend, int divisor) {

        /**
        we check this 
        INT_MIN = -2147483648
        and if divisor is -1
        and this can result in 2147483648
        */

        if (dividend == INT_MIN && divisor == -1)
            return INT_MAX;

        //same hai to 0 diff hai toh 1
        bool negative = (dividend < 0) ^ (divisor < 0);

        long long dvd = llabs((long long)dividend);
        long long dvs = llabs((long long)divisor);

        long long ans = 0;

        while(dvd >= dvs){
            long long temp = dvs;
            long long multiple = 1;

            while((temp << 1) <= dvd){
                temp <<= 1;
                multiple <<= 1;
            }

            dvd -= temp;
            ans += multiple;
        }

        if(negative)
            ans = -ans;
        

        return (int)ans;

        // while (dvd >= dvs) {

        //     long long temp = dvs;
        //     long long multiple = 1;

        //     while ((temp << 1) <= dvd) {
        //         temp <<= 1;
        //         multiple <<= 1;
        //     }

        //     dvd -= temp;
        //     ans += multiple;
        // }

        // if (negative)
        //     ans = -ans;

        // return (int)ans;
    }
};