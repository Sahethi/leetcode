class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int low = 0;
        int high = (m*n)-1;
        int mid = 0;
        while(low <= high){
            mid = low + (high - low) / 2;
            int row = mid / n;
            int col = mid % n;
            int val = matrix[row][col];

            if(val < target){
                low = mid + 1;
            }else if(val > target){
                high = mid - 1;
            }else{
                return true;
            }
        }
        return false;
    }
};