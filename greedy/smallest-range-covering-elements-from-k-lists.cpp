class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        priority_queue<
        tuple<int,int,int>, 
        vector<tuple<int,int,int>>,
        greater<tuple<int, int, int>>
        > pq;

        vector<int> result;
        int maxVal = INT_MIN;
        for(int i=0; i<nums.size(); i++){
            //we want to store value, listIdx, index inside the list elIdx
            //given the lists within the nums are sorted we are taking the min
            //which would be at the 0th position 
            pq.push({nums[i][0], i, 0});
            maxVal = max(maxVal, nums[i][0]); 
        }
        
        int bestStart = get<0>(pq.top());
        int bestEnd = maxVal;

        while(1){
            auto [minVal, listIdx, elIdx] = pq.top(); pq.pop();

            if((maxVal - minVal) < (bestEnd - bestStart)){
                bestEnd = maxVal;
                bestStart = minVal;
            } 

            if(elIdx + 1 == nums[listIdx].size()) break;

            int nextIdx = elIdx + 1;
            int nextVal = nums[listIdx][nextIdx];

            pq.push({nextVal, listIdx, nextIdx});
            maxVal = max(maxVal, nextVal);
        }

        return {bestStart, bestEnd};
    }
};