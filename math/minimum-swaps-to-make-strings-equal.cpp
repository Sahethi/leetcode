class Solution {
public:
    int minimumSwap(string s1, string s2) {
        int i;
        int countXY = 0;
        int countYX = 0;

        for(i=0; i<s1.length(); i++){
            if(s1[i] != s2[i]){
                if(s1[i] == 'x'){
                    countXY++;
                } else {
                    countYX++;
                }
            }
        }

        if((countXY + countYX) % 2) return -1;
        
        return countXY/2 + countYX/2 + (countXY % 2) * 2;

    }
};