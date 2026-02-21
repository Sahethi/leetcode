class Solution {
public:
    int reverse(int x) {
        //classic reveral
        /**
        digit = x % 10;
        x = x / 10;
        rev = rev * 10 + digit;

        - 2^31 ---- ends with 8 INT_MIN
        2^31 - 1 ---- ends with 7 INT_MAX
        */

        int rev = 0;

        while(x != 0){
            int digit = x % 10;
            x = x / 10;

            if(rev > INT_MAX / 10 || rev == INT_MAX / 10 && digit > 7)
                return 0;
            
            if(rev < INT_MIN / 10 || rev == INT_MIN / 10 && digit > 8)
                return 0;

            rev = rev * 10 + digit; 
        }
        return rev;
    }
};