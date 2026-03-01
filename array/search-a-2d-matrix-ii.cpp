class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        //right and down is increase
        //left and up is decrease
        int m = matrix.size();
        int n = matrix[0].size();
        //so the only places we can start top-right and bottom-left
        int row = 0;
        int col = n - 1;
        while(row<m && col>=0){
            int val = matrix[row][col];
            if(val == target) return true;
            if(val > target) col--; else row++;
        }
        return false;
    }
};