class Solution {
public:
    int countSpecialNumbers(int n) {
        string s = to_string(n);
        int len = s.size(); //gettign number of digits
        int ans = 0;

        //counting for lesser digits 9 * P(9, k-1)
        for(int k=1; k<len; k++){
            int count = 9;
            int avail = 9;
            for(int i=1; i<k; i++){
                count *= avail;
                avail--;
            }
            ans += count;
        }

        int mask=0;
        //when we have n digits
        for(int i=0; i<len; i++){
            int digit = s[i] - '0';
            for(int d=(i==0 ? 1 : 0); d<digit; d++){
                //digit is already in use
                if (mask & (1 << d)) continue;
                int remainPos = len - i - 1;
                //__buildin_popcount is used for counting the number of set bits
                int availDigits = 10 - __builtin_popcount(mask) - 1;
                
                int perm = 1;
                for(int k=0; k<remainPos; k++){
                    perm *= (availDigits - k);
                }
                ans += perm;
            }
            //if the current digit is already in use then break
            //mark digit as used
            if (mask & (1 << digit)) break;
        
            // Mark current digit as used
            mask |= (1 << digit);
    
            // If we reached the last digit without breaking, this number itself is valid
            if (i == len - 1) ans++;
        }
        return ans;

    }
};