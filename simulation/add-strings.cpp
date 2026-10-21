class Solution {
public:
    string addStrings(string num1, string num2) {
        int i = num1.size() - 1;
        int j = num2.size() - 1;    
        int carry = 0;
        string ans = "";
        while(i >= 0 || j >= 0 || carry){
            int d1 = (i >= 0) ? num1[i] - '0' : 0;
            int d2 = (j >= 0) ? num2[j] - '0' : 0;

            int sum = d1 + d2 + carry;

            int digit = sum % 10;
            carry = sum / 10;
            ans += digit + '0';

            i--;
            j--;
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};