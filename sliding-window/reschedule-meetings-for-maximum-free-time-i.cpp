class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        int n = startTime.size();
        int windowSum = 0, ans = 0;
        
        for (int i = 0; i <= n; i++) {
            // compute gap on the fly instead of storing
            int gap;
            if (i == 0)         gap = startTime[0];
            else if (i == n)    gap = eventTime - endTime[n-1];
            else                gap = startTime[i] - endTime[i-1];
            
            windowSum += gap;
            if (i >= k) {
                ans = max(ans, windowSum);
                // subtract the gap that's leaving the window
                int old;
                if (i-k == 0)       old = startTime[0];
                else if (i-k == n)  old = eventTime - endTime[n-1];
                else                old = startTime[i-k] - endTime[i-k-1];
                windowSum -= old;
            }
        }
        return ans;
    }
    // int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        // //you will first find all the gaps
        // int n = startTime.size();
        // vector<int>gaps(n+1);
        // gaps[0] = startTime[0];
        // for(int i=1; i<n; i++){
        //     gaps[i] = startTime[i] - endTime[i-1];
        // }
        // gaps[n] = eventTime - endTime[n-1];

        // int windowSum = 0, maxGap = 0;

        // //because there are n+1 gaps
        // for(int i=0; i<=n; i++){
        //     windowSum += gaps[i];

        //     if(i >= k){
        //         maxGap = max(maxGap, windowSum);
        //         windowSum -= gaps[i - k]; //remove the left dhrink
        //     }
        // }
        // return maxGap;
    // }
};