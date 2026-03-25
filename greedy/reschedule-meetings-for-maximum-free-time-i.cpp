class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        int n = startTime.size();
        
        // Build gaps array: n+1 gaps
        vector<int> gaps(n + 1);
        gaps[0] = startTime[0];                          // before first meeting
        for (int i = 1; i < n; i++)
            gaps[i] = startTime[i] - endTime[i - 1];    // between meetings
        gaps[n] = eventTime - endTime[n - 1];            // after last meeting

        // Sliding window of size k+1
        int windowSum = 0, ans = 0;
        for (int i = 0; i <= n; i++) {
            windowSum += gaps[i];
            if (i >= k) {                                // window is full
                ans = max(ans, windowSum);
                windowSum -= gaps[i - k];
            }
        }
        return ans;
    }
};