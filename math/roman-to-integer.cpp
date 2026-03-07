class Solution {
public:
    int romanToInt(string s) {
        int I=1, v=5, x=10, l=50, c=100, d=500, m=1000;
        int res=0;
        for(int i=0; i<s.length(); i++){
            if(i + 1 < s.length() && s[i] == 'I' && s[i+1] == 'V'){
                res += 4;
                i++;
            }
            else if(i + 1 < s.length() && s[i] == 'I' && s[i+1] == 'X'){
                res += 9;
                i++;
            }
            else if(i + 1 < s.length() && s[i] == 'X' && s[i+1] == 'L'){
                res += 40;
                i++;
            }
            else if(i + 1 < s.length() && s[i] == 'X' && s[i+1] == 'C'){
                res += 90;
                i++;
            }
            else if(i + 1 < s.length() && s[i] == 'C' && s[i+1] == 'D'){
                res += 400;
                i++;
            }
            else if(i + 1 < s.length() && s[i] == 'C' && s[i+1] == 'M'){
                res += 900;
                i++;
            } else {
                if(s[i] == 'I') res += I;
                else if(s[i] == 'V') res += v;
                else if(s[i] == 'X') res += x;
                else if(s[i] == 'L') res += l;
                else if(s[i] == 'C') res += c;
                else if(s[i] == 'D') res += d;
                else if(s[i] == 'M') res += m;
            }
        }
        return res;
    }
};