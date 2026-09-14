class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {

        vector<vector<int>> matrix(n, vector<int>(n));

        int top = 0, left = 0, right = n-1, bottom = n-1;
        int num = 1;

        while(top <= bottom && left <= right){
            //movement would be right -> down -> left -> top

            //moving right
            for(int j=left; j<=right; j++){
                matrix[top][j] = num;
                num++;
            }
            top++;


            //movinf down
            for(int i=top; i<=bottom; i++){
                matrix[i][right] = num;
                num++;
            }
            right--;

            if(top <= bottom){
                //movinf left
                for(int i=right; i>=left; i--){
                    matrix[bottom][i] = num;
                    num++;
                }
                bottom--;
            }
            
            if(left <= right){
                //moving up 
                for(int i=bottom; i>=top; i--){
                    matrix[i][left] = num;
                    num++;
                }
                left++;
            }
            
        }

        return matrix;

        //if n is odd i think we will visit the cell middle cell right side elements again
    }
};