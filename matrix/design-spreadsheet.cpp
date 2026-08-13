class Spreadsheet {
private:
    int getCellValue(string x){
        if(x[0] >= 'A' && x[0] <= 'Z'){
            //cell reference
            int col = x[0] - 'A';
            int row = stoi(x.substr(1));
            return grid[row-1][col];
        }else{
            //its a digit
            return stoi(x);
        }
    }
public:
    //like there are 26 columns A-Z
    //and given number of rows
    //each cell can hold value from 0 - 10^5
    vector<vector<int>> grid;
    
    Spreadsheet(int rows) {
        grid.resize(rows, vector<int>(26, 0));
    }
    
    void setCell(string cell, int value) {
        int col = cell[0] - 'A';
        int row = stoi(cell.substr(1));
        grid[row-1][col] = value;
    }
    
    void resetCell(string cell) {
        int col = cell[0] - 'A';
        int row = stoi(cell.substr(1));
        grid[row-1][col] = 0;
    }
    
    int getValue(string formula) {
        //=A1+B1
        //5 is len and pos is 2
        //5 - 2 = 3 
        int pos = formula.find('+');
        string x = formula.substr(1,pos-1);
        string y = formula.substr(pos+1);

        int val1 = getCellValue(x);
        int val2 = getCellValue(y);

        return val1+val2;
    }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */