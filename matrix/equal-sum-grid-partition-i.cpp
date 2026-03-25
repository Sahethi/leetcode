class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();

        long long sum = 0;
        for(auto& row : grid){
            for(int val : row){
                sum += val;
            }
        }

        int topSum = 0;
        for(int i=0; i<m-1; i++){
            for(int j=0; j<n; j++){
                topSum += grid[i][j];
            }

            int bottomSum = sum - topSum;

            if(bottomSum == topSum) return true;
        }


        int leftSum = 0;
        for(int j =0; j<n-1; j++){
            for(int i=0; i<m; i++){
                leftSum += grid[i][j];
            }

            int rightSum = sum - leftSum;

            if(rightSum == leftSum) return true;
        }

        return false;
    }
};