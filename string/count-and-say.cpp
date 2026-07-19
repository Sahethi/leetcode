class Solution {
public:
    string countAndSay(int n) {

        string s = "1";

        if(n == 1) return s;

        for(int i=0; i<n-1; i++){

            int j=0; 
            string next = "";

            //processing the current string that we have
            while(j < s.length()){
                
                int count = 1;

                while(j + 1 < s.length() && s[j] == s[j+1]){
                    j++;
                    count++;
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