class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        vector<vector<int>> graph(n);
        vector<int> indegree(n, 0);

        for(auto r : relations){
            int child = r[1]-1;
            int parent = r[0]-1;

            graph[parent].push_back(child);
            indegree[child]++;
        }

        queue<int> q;
        vector<int> dp(n, 0);

        for(int i=0; i<n; i++){
            if(indegree[i] == 0){
                q.push(i);
                dp[i] = time[i];
            }
        }

        //kahn algo
        while(!q.empty()){
            int curr = q.front();
            q.pop();

            for(int next : graph[curr]){
                dp[next] = max(dp[next], dp[curr] + time[next]);
                indegree[next]--;
                if(indegree[next] == 0) q.push(next);
            }
        }

        return *max_element(dp.begin(), dp.end());
    }
};