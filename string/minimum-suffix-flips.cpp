class Solution {
public:
    int minFlips(string target) {
        int count = 0;
        char state = '0';
        for (char c : target) {
            if (c != state) {
                count++;
                state = c;
            }
        }
        return count;
    }

    // int minFlips(string target){
    //     int count = 0;
    //     for(int i=1; i<target.size(); i++){
    //         if(target[i] ^ target[i-1]){
    //             count++;
    //         }
    //     }
    //     return target[0] == '0' ? count : count+1;
    // }
};
