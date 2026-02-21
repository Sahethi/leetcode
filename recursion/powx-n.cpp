class Solution {
public:
    double myPow(double x, int n) {
        //in this problem we use binary exponentiation 
        //that is to find x^n
        //let's take the example of x = 7 and n = 11
        // 11 -> 1011 in binary
        // corresponding bit is like 2^3 + 2^2 + 2^1 + 2^0
        // we will only calculate the 8 4 2 1
        // for 7 -> 7^8 + 7^2 + 7^1 = 7^11 (8 + 2 + 1)
        // this will take log (n) ops

        // if(n < 0){
        //     x = 1/x;
        // } 

        // //taking absolute value of n
        // long num = labs(n);
        // double pow = 1;
        // while(num != 0){
        //     //basically checking if the last bit is set
        //     if((num & 1) != 0){
        //         pow *= x;
        //     }
            
        //     x *= x;
        //     num >>= 1; // checking the next set bit, this divdes the number by 2
        // }

        // return pow;

        if(n < 0){
            x = 1/x;
        }

        long num = labs(n);
        double pow = 1;
        while(num != 0){
            if((num & 1) != 0){
                pow = pow * x;
            }

            x = x * x;
            num = num >> 1;
        }

        return pow;

    }
};