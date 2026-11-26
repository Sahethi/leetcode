class Solution {
public:
    long long minimumSteps(string s) {
        //1 is black and 0 is white
        //000111
        //u want all white balls to left and black to right
        long long swaps = 0;
        int countOnes = 0;
        for(char c : s){
            if(c == '1'){
                countOnes++;
            }else{
                swaps += countOnes;
            }
        }

        return swaps;
    }
};