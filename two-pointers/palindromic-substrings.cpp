class Solution {
public:
    int countSubstrings(string s) {
        //so there are always 2 types of centers
        //one is the character itself and one is the space between 2 characters
        //a(space)a here the space is the center when the string is even and 'a' this is the center when the string is odd
        //therefore you can say its (n) + (n-1) center = 2n - 1

        //you will be checking palindrome for each center like exapnd around it
        int len = s.length();
        if (len == 0){
            return 0;
        }

        int count = 0;

        for (int i=0; i<len; i++){
            //case 1 when length is odd which means center is i
            int l = i;
            int r = i;
            while(l >=0 && r < len and s[l] == s[r]){
                count++;
                // bsically expanding around it <---l (center) r--->
                l--;
                r++;
            }

            //case 2 when length is even and space is the center
            // a b b a here center is between two b's
            l = i;
            r = i+1;
            while (l>=0 && r<len && s[l] == s[r]){
                count++;
                l--;
                r++;
            }
        }

        return count;
    }
};