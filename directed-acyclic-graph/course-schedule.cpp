class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        vector<int> indegree(numCourses, 0);

        //building the graph and calculatign in degrees
        for(auto& p : prerequisites){
            int course = p[0];
            int preReq = p[1];
            graph[preReq].push_back(course);
            indegree[course]++;
        }

        //intitilaise queue with in degree 0
        queue<int> q;

        for(int i=0; i<numCourses; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }

        int processed = 0;
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            processed++;
            
            for(int next: graph[curr]){
                indegree[next]--;
                if(indegree[next] == 0){
                    q.push(next);
                }
            }
        }

        return numCourses == processed;
    }
};