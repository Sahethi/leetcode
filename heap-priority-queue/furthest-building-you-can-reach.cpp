class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int i = 0;
        priority_queue<int, vector<int>, greater<int>> pq;
        for(i=0; i<heights.size()-1; i++){
            if(heights[i] < heights[i+1]){
                int climb = heights[i+1] - heights[i];
                pq.push(climb);
                if(pq.size() > ladders){
                    int top = pq.top();
                    pq.pop();
                    if(top <= bricks)
                        bricks = bricks - top;
                    else return i;
                }
            }
        }
        return i;
    }
};