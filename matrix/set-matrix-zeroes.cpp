class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int row_size = matrix.size();
        int col_size = matrix[0].size();
        bool col_0 = false;

        for(int i=0; i<row_size; i++){
            if(matrix[i][0] == 0) col_0 = true;
            for(int j=1; j<col_size; j++){
                if(matrix[i][j] == 0){
                    matrix[i][0] = matrix[0][j] = 0;
                }
            }
        }

        for(int i=1; i<row_size; i++){
            for(int j=1; j<col_size; j++){
                if(matrix[i][0] == 0 || matrix[0][j] == 0)
                    matrix[i][j] = 0;
            }
        }

        if(matrix[0][0] == 0){
            for(int j=1; j<col_size; j++){
                matrix[0][j] = 0;
            }
        }

        if(col_0){
            for(int i=0; i<row_size; i++){
                matrix[i][0] = 0;
            }
        }
    }
};