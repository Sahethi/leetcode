class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        //u can use quick select cause u need the kth elements
        priority_queue<pair<int, vector<int>>> pq;
        for(auto& point : points){
            int x = point[0];
            int y = point[1];
            int dist = x*x + y*y;
            pq.push({dist, point});
            if(pq.size() > k){
                pq.pop(); // keep only the k elements
            }
        }

        vector<vector<int>> result;
        while(!pq.empty()){
            result.push_back(pq.top().second);
            pq.pop();
        }
        return result;
    }
};