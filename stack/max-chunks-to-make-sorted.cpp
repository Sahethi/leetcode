class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        
        int chunks = 0;
        int maxSeen = INT_MIN;
        for(int i=0; i<arr.size(); i++){
            maxSeen = max(maxSeen, arr[i]);
            if(maxSeen == i){
                chunks++;
            }
        }

        return chunks;
    }
};