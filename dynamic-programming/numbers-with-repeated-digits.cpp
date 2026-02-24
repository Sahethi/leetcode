class Solution {
private:
    int countSpecialIntegers(int n){
        string s = to_string(n);
        int len = s.size();
        int ans = 0;

        //finding permutations for len-1
        // 9 * P(9, k-1) --- 9 * (9 * 8 * 7 ... 6)
        for(int i=1; i<len; i++){
            int count = 9;
            int avail = 9;
            for(int k=1; k<i; k++){
                count *= avail;
                avail--;
            }
            ans += count;
        }

        //now we are solving we len is n digits
        int mask = 0;
        for(int i=0; i<len; i++){
            int digit = s[i] - '0';
            for(int d = (i==0 ? 1 : 0); d<digit; d++){
                //id the digit is already used then skip
                if(mask & (1 << d)) continue;

                int remainPos = len - i - 1;
                int availDigits = 10 - __builtin_popcount(mask) - 1;
                int perm = 1;
                for(int k=0; k<remainPos; k++){
                    perm *= (availDigits-k);
                }
                ans += perm;
            }
            //if n itself has a repeated char then break 
            if(mask & (1 << digit)) break;

            //marked as used
            mask |= (1 << digit);

            if(i == len -1) ans++;
        }
        return ans;
    }
public:
    int numDupDigitsAtMostN(int n) {
        return n - countSpecialIntegers(n);
    }
};