class Solution {
public:
    int totalSum = 0;
    unordered_map<int, int> tree; 
    void dfs(int depth, int position, int currentSum){
        int currentKey = depth * 10 + position;
        currentSum += tree[currentKey];
        // check for left child and right child
        int offset = 10 + (position - 1);
        int leftKey = currentKey + offset;
        int rightKey = leftKey + 1;
        int leftPos = 2 * position-1;
        int rightPos = 2 * position;

        // int leftKey = (depth + 1) * 10 + (2 * position - 1);
        // int rightKey = (depth + 1) * 10 + (2 * position);

        bool leftExists = tree.count(leftKey);
        bool rightExists = tree.count(rightKey);
        if(!leftExists && !rightExists){
            totalSum += currentSum;
            return;
        }

        if(leftExists){
            dfs(depth + 1, leftPos, currentSum);
        }
        if(rightExists){
            dfs(depth + 1, rightPos, currentSum);
        }
        
    }
    int pathSum(vector<int>& nums) {
        //key = 1 x 10 + 1 = 11 // here the depth = 1 and pos = 1
        //as map doesnt allow us to store the depth and pos as a pair for the key
        
        for(int n: nums){
            int depth = n / 100; // get the first digit
            int pos = (n / 10) % 10; // to get second digit
            int value = n % 10; // to get the last digit
            tree[depth * 10 + pos] = value;

            //in case i have 4 digits and iwant to get the 2nd digit 100th place
            // (n/100) % 10
            // 3rd digit (n/10) % 10
            //if you want both (n/10) % 100
        }

        dfs(1,1,0);
        return totalSum;
    }
};