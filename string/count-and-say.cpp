class Solution {
public:
    string countAndSay(int n) {

        string s = "1";

        if(n == 1) return s;

        for(int i=0; i<n-1; i++){
            string next = "";
            int j=0;

            while(j < s.length()){
                //as we have already seen 1 char
                int count = 1;

                while(s[j+1] && s[j] == s[j+1]){
                    count++;
                    j++;
                }
                next += to_string(count);
                next += s[j];
                j++;
                
            }
            s = next;
        }

        return s;
    }
};