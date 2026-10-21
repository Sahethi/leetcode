class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        //brute force will be TLE n*m
        int n = intervals.size();
        int m = queries.size();

        vector<pair<int, int>> queriesIdx;

        int i=0;
        for(int q : queries)
            queriesIdx.push_back({q, i++});

        sort(queriesIdx.begin(), queriesIdx.end());
        sort(intervals.begin(), intervals.end());

        //declare heap stores size and right
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

        int j=0;
        vector<int> ans(m, -1);

        for(auto& [q, idx] : queriesIdx){
            
            while(j < n && intervals[j][0] <= q){
                int l = intervals[j][0];
                int r = intervals[j][1];
                int size = r - l + 1;

                pq.push({size, r});
                j++;
            }
            

            //pop any invalid intervals
            //if right is < than q then pop
            while(!pq.empty() && pq.top().second < q){
                pq.pop();
            }

            if(!pq.empty()){
                ans[idx] = pq.top().first;
            }
        }

        return ans;
    }
};