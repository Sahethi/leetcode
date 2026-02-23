class Solution {
public:
    int buttonWithLongestTime(vector<vector<int>>& events) {
        int maxTime = 0, maxIdx =0;
        int i;
        for(i=0; i<events.size()-1; i++){
            int diff = events[i+1][1] - events[i][1];
            if(maxTime < diff) maxIdx = events[i][0];
            maxTime = max(maxTime, diff);
        }
        int diff = events[i+1][1] - events[i][1];
            if(maxTime < diff) maxIdx = events[i][0];
            maxTime = max(maxTime, diff);
        return maxIdx;
    }
};