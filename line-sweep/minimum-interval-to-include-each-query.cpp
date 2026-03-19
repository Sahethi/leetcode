class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        //brute force will be TLE n*m
        vector<pair<int, int>> queryIndex;
        int n = intervals.size();
        int m = queries.size();

        vector<int> ans(m, -1);

        int i=0;
        for(int q : queries){
            queryIndex.push_back({q, i++});
        }

        sort(queryIndex.begin(), queryIndex.end());
        sort(intervals.begin(), intervals.end());

        //store size and right
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        int j = 0;
        for(auto& [q, idx] : queryIndex){
            while(j < n && intervals[j][0] <= q){
                int l = intervals[j][0];
                int r = intervals[j][1];
                int size = r - l + 1;
                
                pq.push({size, r});
                j++;
            }

            //if the right is less than q then pop
            while(!pq.empty() && pq.top().second < q){
                pq.pop();
            }

            if(!pq.empty()){
                ans[idx] = pq.top().first;
            }else{
                ans[idx] = -1;
            }
        }

        return ans;
    }
};