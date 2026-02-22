class Solution {
// public:
//     int minFlips(string target) {
//     int count = 0;
//     char state = '0';
//     for (char c : target) {
//         if (c != state) {
//             count++;
//             state = c;
//         }
//     }
//     return count;
// }
// };
public:
    int minFlips(string target) {
        
        int count = 0;
        for(int i=0; i<target.size()-1; i++){
            if(target[i] ^ target[i+1])
                count++;
        }
        return (target[0] == '0' ? 0 : count+1);
    }
};
