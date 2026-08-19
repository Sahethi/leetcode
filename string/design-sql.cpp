class SQL {
private:
    //how many columns does the table users have like 3 so users->3
    unordered_map<string, int> cols;
    //given this particular table name, whats the nextId i should be assigning
    unordered_map<string, int> nextId;
    //these are the table name, id and row 
    unordered_map<string, map<int, vector<string>>> rows;
public:
    SQL(vector<string>& names, vector<int>& columns) {
        
        for(int i=0; i<names.size(); i++){
            cols[names[i]] = columns[i];
            nextId[names[i]] = 1;
        }
    }
    
    bool ins(string name, vector<string> row) {
        
        if(cols.find(name) == cols.end()) return false;
        if(row.size() != cols[name]) return false;

        int currId = nextId[name];
        rows[name][currId] = row;
        nextId[name]++;
        return true;
    }
    
    void rmv(string name, int rowId) {
        if(cols.find(name) == cols.end()) return;
        if(rows[name].find(rowId) == rows[name].end()) return;

        rows[name].erase(rowId);
    }
    
    string sel(string name, int rowId, int columnId) {
        if(cols.find(name) == cols.end()) return "<null>";
        if(rows[name].find(rowId) == rows[name].end()) return "<null>";
        //we never delete columns we only delete rows
        if(columnId < 1 || columnId > cols[name]) return "<null>";

        //columns index is like 1-indexed to access it we use -1
        return rows[name][rowId][columnId-1];
    }
    
    vector<string> exp(string name) {
        if(cols.find(name) == cols.end()) return {};
    
        vector<string> result;
        for(auto &[id, row] : rows[name]){
            string current = to_string(id);
            for(string val : row){
                current += "," + val;
            }
            result.push_back(current);
        }
        return result;
    }
};

/**
 * Your SQL object will be instantiated and called as such:
 * SQL* obj = new SQL(names, columns);
 * bool param_1 = obj->ins(name,row);
 * obj->rmv(name,rowId);
 * string param_3 = obj->sel(name,rowId,columnId);
 * vector<string> param_4 = obj->exp(name);
 */