/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:
    Node* divide(vector<vector<int>>& grid, int r, int c, int length){
        int startValue = grid[r][c];
        int mixed = false;
        for(int i=r; i<r+length; i++){
            for(int j=c; j<c+length; j++){
                if(grid[i][j] != startValue){
                    mixed = true;
                    break;
                }
            }
        }

        if(mixed == false){
            return new Node(startValue, true);
        }else{
            Node* internalNode = new Node(1, false);
            int half = length / 2;

            internalNode->topLeft = divide(grid, r, c, half);
            internalNode->topRight = divide(grid, r, c+half, half);
            internalNode->bottomLeft = divide(grid, r+half, c, half);
            internalNode->bottomRight = divide(grid, r+half, c+half, half);
            return internalNode;
        }
    }
    Node* construct(vector<vector<int>>& grid) {
        //so in a quad tree each node has 4 children
        /**
        and each node has 2 attributes ... val and isLeaf

        val 
        is true if the grid is of 1s
        false if the node represents a grid of 0s

        isLeaf
        true if its leaf
        false if it has children

        it is basically divide and conquer
        */
        return divide(grid, 0, 0, grid.size());
    }
};