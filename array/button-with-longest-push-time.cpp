class Solution {
public:
    int buttonWithLongestTime(vector<vector<int>>& events) {
        int maxTime = events[0][1], maxIdx = events[0][0];
        for(int i=1; i<events.size(); i++){
            int diff = events[i][1] - events[i-1][1];
            if(maxTime < diff ){
                maxTime = diff;
                maxIdx = events[i][0];
            }
            maxTime = max(maxTime, diff);
        }
        return maxIdx;
    }
};
