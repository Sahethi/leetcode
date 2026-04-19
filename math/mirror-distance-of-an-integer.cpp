class Solution {
public:
    int mirrorDistance(int n) {

        // string s = to_string(n);

        // reverse(s.begin(), s.end());
        // int reversedInt = stoi(s);
        
        // int ans = abs(n - reversedInt);

        // return ans;

        long long rev = 0;
        int temp = n;
        while(n != 0){
            int digit = n % 10;
            n = n / 10;
            rev = rev * 10 + digit;
        }

        return abs(temp - rev);
    }
};