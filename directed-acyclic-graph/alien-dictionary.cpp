class Solution {
public:
    string alienOrder(vector<string>& words) {
        unordered_map<char, unordered_set<char>> adj;
        unordered_map<char, int> inDegree;

        for(string& word : words){
            for(char c : word){
                if(inDegree.find(c) == inDegree.end()){
                    inDegree[c] = 0;
                }
            }
        }

        for(int i=0; i<words.size()-1; i++){
            string w1 = words[i];
            string w2 = words[i+1];

            if(w1.size() > w2.size() && w1.compare(0, w2.size(), w2) == 0){
                return "";
            }

            for(int j=0; j<min(w1.size(), w2.size()); j++){
                if(w1[j] != w2[j]){
                    char parent = w1[j];
                    char child = w2[j];

                    if(adj[parent].find(child) == adj[parent].end()){
                        adj[parent].insert(child);
                        inDegree[child]++;
                    }
                    break;
                }
            }
        }

        //topological sort or kahn's algorithm
        queue<char> q;
        string result = "";

        for (const auto& [ch, deg] : inDegree) {
            if (deg == 0) {
                q.push(ch);
            }
        }

        while(!q.empty()){
            char curr = q.front();
            q.pop();
            result += curr;

            for(char neighbor : adj[curr]){
                inDegree[neighbor]--;
                if(inDegree[neighbor] == 0){
                    q.push(neighbor);
                }
            }
        }

        return result.size() == inDegree.size() ? result : "";
    }
};