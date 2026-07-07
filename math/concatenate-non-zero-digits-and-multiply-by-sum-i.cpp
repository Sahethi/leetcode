class Solution {
public:
    long long sumAndMultiply(int n) {
        long long sum = 0;
        string ans = "";
        string s = to_string(n);

        for(char c : s){
            if(c != '0'){
                ans += c;
                sum += c - '0';
            }
        }

        if(ans == "") ans = "0";

        long long x = stoi(ans);


        return x * sum;
    }
};