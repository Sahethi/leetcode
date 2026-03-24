class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        
        if(intervals.empty()) return 0;

        //sorting by start times
        sort(intervals.begin(), intervals.end());

        //declaring minHeap
        priority_queue<int, vector<int>, greater<int>> pq;
        
        //pushing the end times
        pq.push(intervals[0][1]);;
        for(int i=1; i<intervals.size(); i++){
            //if a starttime ends before a another meeting end then it can be reused
            if(intervals[i][0] >= pq.top()){
                pq.pop();
            }
            pq.push(intervals[i][1]);
        }

        return pq.size();
        
        
        
        
        
        
        
        
        
        
        // if(intervals.empty()) return 0;

        // //sorting by start times
        // sort(intervals.begin(), intervals.end());

        // //prirotiy queue is only looking at the end times
        // priority_queue<int, vector<int>, greater<int>> minHeap;

        // minHeap.push(intervals[0][1]);
        // for(int i=1; i<intervals.size(); i++){
        //     if(intervals[i][0] >= minHeap.top()){
        //         minHeap.pop();
        //     }
        //     minHeap.push(intervals[i][1]);
        // } 

        // return minHeap.size();
    }
};