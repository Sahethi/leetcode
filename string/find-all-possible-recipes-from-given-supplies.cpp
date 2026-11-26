class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        
        /**
        You can notice that for every recipe, the ingredient corresponds to the ingredients that are required to make that recipe. 
        */

        unordered_map<string, vector<string>> graph;
        unordered_map<string, int> indegree;

        queue<string> q;
        vector<string> result;

        for(int i=0; i<recipes.size(); i++){
            indegree[recipes[i]] = ingredients[i].size();

            for(string ing : ingredients[i]){
                graph[ing].push_back(recipes[i]);
            }
        }

        for(string sup : supplies){
            q.push(sup);
        }

        while(!q.empty()){
            string curr = q.front();
            q.pop();

            for(string next : graph[curr]){
                indegree[next]--;

                if(indegree[next] == 0){
                    result.push_back(next);
                    q.push(next);
                }
            }
        }

        return result;
    }
};