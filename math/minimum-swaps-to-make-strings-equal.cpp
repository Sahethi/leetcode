class Solution {
public:
    int minimumSwap(string s1, string s2) {
        int countY = 0, countX = 0;
        int swaps = 0;
        int i;
        for(i=0; i<s1.length()-1; i++){
            if(s1[i] != s2[i]){
                if(s1[i] == 'x' && s1[i+1] == 'x' && s2[i] == 'y' && s2[i+1] == 'y'){
                    swaps++;
                }
                if(s1[i] == 'x' && s1[i+1] == 'y' && s2[i] == 'y' && s2[i+1] == 'x'){
                    swaps += 2;
                }
            }
            if(s1[i] == 'x') countX++;
            if(s1[i] == 'y') countY++;
            if(s2[i] == 'x') countX++;
            if(s2[i] == 'y') countY++;
        }

        if(s1[i] == 'x') countX++;
        if(s1[i] == 'y') countY++;
        if(s2[i] == 'x') countX++;
        if(s2[i] == 'y') countY++;

        if(countX % 2 != 0 && countY % 2 != 0) return -1;
        return swaps;
    }
};