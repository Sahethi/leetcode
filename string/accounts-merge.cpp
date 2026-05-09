class UnionFind {
private:
    vector<int> parent;
    
public:
    UnionFind(int n) {
        parent.resize(n);
        for (int i=0; i<n; i++) {
            parent[i] = i;
        }
    }
    
    int find(int x) {
        if (parent[x] == x) {
            return x;
        }
        parent[x] = find(parent[x]);  // Path compression
        return parent[x];
    }
    
    void unify(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX < rootY) {
            parent[rootY] = parent[rootX];
        } else {
            parent[rootX] = parent[rootY];
        }
    }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        UnionFind uf(n);
        
        unordered_map<string, int> emails;  // email -> account ID
        unordered_map<int, string> name;    // account ID -> name
        unordered_map<string, int> seen;    // email -> first account ID
        
        // Phase 1: Build unions based on shared emails
        for (int id=0; id<n; id++) {
            name[id] = accounts[id][0];
            for (int i=1; i<accounts[id].size(); i++) {
                string email = accounts[id][i];
                emails[email] = id;
                if (seen.count(email)) {
                    uf.unify(id, seen[email]);
                } else {
                    seen[email] = id;
                }
            }
        }
        
        // Phase 2: Group emails by their root account
        unordered_map<int, set<string>> filtered;
        for (auto& [email, id] : emails) {
            int root = uf.find(id);
            filtered[root].insert(email);
        }
        
        // Phase 3: Format the output
        vector<vector<string>> res;
        for (auto& [k, v] : filtered) {
            vector<string> cur;
            cur.push_back(name[k]);
            for (const string& email : v) {
                cur.push_back(email);
            }
            res.push_back(cur);
        }
        
        return res;
    }
};