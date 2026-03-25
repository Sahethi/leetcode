class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        //you will first find all the gaps
        int n = startTime.size();
        vector<int>gaps(n+1);
        gaps[0] = startTime[0];
        for(int i=1; i<n; i++){
            gaps[i] = startTime[i] - endTime[i-1];
        }
        gaps[n] = eventTime - endTime[n-1];

        int windowSum = 0, maxGap = 0;

        for(int i=0; i<=n; i++){
            windowSum += gaps[i];

            if(i >= k){
                maxGap = max(maxGap, windowSum);
                windowSum -= gaps[i - k]; //remove the left dhrink
            }
        }
        return maxGap;
    }
};