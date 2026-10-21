class Solution {
public:
    int largestInteger(int n, int s) {
        /**

        soo if n is 2 the only possible sums
        if n = 2 sum can range from 1 to 18
        if n = 3 sum can range from 1 to 27
        if n = 5 sum can range from 1 to 45

        example sum is 9 and n = 2 
        which 5 digits make up 45

        99998 = 44 
        max = 99999 target number is 43
        maxN = 45 - 43 = 2 

        return maxNum - 2
        **/

        if(s == 0) return 0;
        if(s > n * 9) return -1;

        string ans = "";

        for(int i=0; i<n; i++){
            if(s == 0){
                ans += "0";
            }else{
                int d = min(9,s);
                ans += to_string(d);
                s = s - d;
            }
        }

        return stoi(ans);
    }
};