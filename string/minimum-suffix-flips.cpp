class Solution {
public:
    int minFlips(string target) {
        
        int count = 0;
        for(int i=1; i<target.size(); i++){
            if(target[i] ^ target[i+1])
                count++;
        }
        return (target[0] == '0' ? 0 : count+1);
    }
};