class Solution {
public:
    void bitFlip(vector<int> &row){
        for(int i=0; i<row.size(); i++){
            row[i] = row[i] == 0 ? 1 : 0;
        }
    }
    void horizontalFlip(vector<int> &row){
        reverse(row.begin(), row.end());
    }
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        /**
        1 1 0 -> 0 0 1 -> 1 0 0 
        1 0 1 -> 0 1 0 -> 0 1 0 
        0 0 0 -> 1 1 1 -> 1 1 1 
        */

        vector<vector<int>> result;

        for(auto& row : image){
            horizontalFlip(row);
            bitFlip(row);
            result.push_back(row);
        }

        return result;

    }
};