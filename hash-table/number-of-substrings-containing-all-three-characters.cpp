class Solution {
public:
    int numberOfSubstrings(string s) {
        vector<int> lastSeen(3, -1);

        int count = 0;  
        int n = s.size();

        for(int i=0; i<n; i++){
            
            lastSeen[s[i] - 'a'] = i;

            if(lastSeen[0] != -1 && lastSeen[1] != -1 && lastSeen[2] != -1){
                count += min({lastSeen[0], lastSeen[1], lastSeen[2]}) + 1;
                // count += (minIdx + 1);
            }
        }

        return count;
    }
};