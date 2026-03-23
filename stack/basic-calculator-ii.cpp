class Solution {
public:
    int calculate(string s) {
        int ans = 0;
        int lastNum = 0;
        int currNum = 0;
        char op = '+';

        for(int i=0; i<s.size(); i++){
            char c = s[i];

            if(isdigit(c)){
                currNum = currNum * 10 + (c- '0');
            }

            if((!isdigit(c) && c != ' ' )|| i == s.size()-1){
                if(op == '*'){
                    lastNum = lastNum * currNum;
                } else if(op == '/'){    
                    lastNum = lastNum / currNum;
                } else if (op == '+') {
                    ans += lastNum;
                    lastNum = currNum;
                } else if (op == '-') {
                    ans += lastNum;
                    lastNum = -currNum;
                }

                op = c;
                currNum = 0;
            }
        }
        return ans + lastNum;
    }
};