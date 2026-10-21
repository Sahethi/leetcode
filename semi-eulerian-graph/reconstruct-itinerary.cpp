class Solution{
    private:
        void dfs(string source, unordered_map<string, multiset<string>> &graph,
        vector<string>& result){
            while(!graph[source].empty()){

                //to get the iterator;
                auto it = graph[source].begin();
                string next = *it;
                graph[source].erase(it);
                dfs(next, graph, result);

            }
            result.push_back(source);
        }
    public:
        vector<string> findItinerary(vector<vector<string>>& tickets) {
            unordered_map<string, multiset<string>> graph;

            for(auto& ticket : tickets){
                string source = ticket[0];
                string dest = ticket[1];
                graph[source].insert(dest);
            }

            vector<string> result;
            dfs("JFK", graph, result);
            reverse(result.begin(), result.end());
            return result;
        }
};

// class Solution {
// private:
//     void dfs(vector<string>& result,string airport, unordered_map<string, multiset<string>>& graph){
//         while(!graph[airport].empty()){
//             auto it = graph[airport].begin();
//             string next = *it;
//             graph[airport].erase(it);
//             dfs(result, next, graph);
//         }
//         result.push_back(airport);
//     }
// public:
//     vector<string> findItinerary(vector<vector<string>>& tickets) {
//         unordered_map<string, multiset<string>> graph;

//         for(auto& ticket : tickets){
//             string source = ticket[0];
//             string dest = ticket[1];
//             graph[source].insert(dest);
//         }

//         vector<string> result;
//         dfs(result, "JFK", graph);
//         reverse(result.begin(), result.end());
//         return result;
//     }
// };