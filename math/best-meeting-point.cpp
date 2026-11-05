class Solution {
public:
    int minTotalDistance(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<int> rows;
        vector<int> cols;

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 1){
                    rows.push_back(i);
                }
            }
        }

        for(int j=0; j<n; j++){
            for(int i=0; i<m; i++){
                if(grid[i][j] == 1){
                    cols.push_back(j);
                }
            }
        }

        /**
        now that you know the coordinates u have, u can look into the median row and col but for that we want the points to be sorted
        given the manhattan distance we are looking at rows and cols independently
        **/
        
        // for(auto& coord : coords){
        //     rows.push_back(coord.first);
        //     cols.push_back(coord.second);
        // }
        // sort(rows.begin(), rows.end());
        // sort(cols.begin(), cols.end());

        //should work for both even and odd
        int medianRow = rows[rows.size()/2];
        int medianCol = cols[cols.size()/2];

        //now we know the best meeting point is medianRow,medianCol

        int bestDist = 0;

        for (int r : rows) 
            bestDist += abs(r - medianRow);

        for (int c : cols)
            bestDist += abs(c - medianCol);

        return bestDist;
    }
};