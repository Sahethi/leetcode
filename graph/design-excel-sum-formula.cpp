class Excel {
private:
    vector<vector<int>> grid; // this works for storing values
    //but u need to store formulas
    vector<vector<vector<pair<int,int>>>> formula;

    int evaluate(int r, int c){
        if(formula[r][c].empty()){
            return grid[r][c];
        }

        int ans = 0;
        for(auto [rr,cc] : formula[r][c]){
            ans += evaluate(rr,cc); //recursively find value sort of dfs
        }
        return ans;
    }
public:
    Excel(int height, char width) {
        grid.resize(height, vector<int>(width - 'A' + 1, 0));

        formula.resize(height, vector<vector<pair<int,int>>>(width - 'A' + 1));
    }
    
    void set(int row, char column, int val) {
        grid[row-1][column - 'A'] = val;
        formula[row-1][column-'A'].clear();
    }
    
    int get(int row, char column) {
        return evaluate(row-1, column - 'A');
    }
    
    int sum(int row, char column, vector<string> numbers) {

        int r = row - 1;
        int c = column - 'A';
        
        //forget whatever formula was there before
        formula[r][c].clear();

        int ans = 0;
        for(string s : numbers){
            //here string can be A1 or A1:B2
            if(s.find(':') == string::npos){
                //single cell
                int cc = s[0] - 'A';
                int rr = stoi(s.substr(1)) - 1;

                formula[r][c].push_back({rr,cc});
            }else{
                //range
                int colon = s.find(':');

                string start = s.substr(0, colon);
                string end = s.substr(colon+1);

                int c1 = start[0] - 'A';
                int r1 = stoi(start.substr(1)) - 1;

                int c2 = end[0] - 'A';
                int r2 = stoi(end.substr(1)) - 1;

                for(int r3=r1; r3<=r2; r3++){
                    for(int c3=c1; c3<=c2; c3++){
                        formula[r][c].push_back({r3, c3});
                    }
                }
            }
        }
        return evaluate(r,c);
    }
};

/**
 * Your Excel object will be instantiated and called as such:
 * Excel* obj = new Excel(height, width);
 * obj->set(row,column,val);
 * int param_2 = obj->get(row,column);
 * int param_3 = obj->sum(row,column,numbers);
 */