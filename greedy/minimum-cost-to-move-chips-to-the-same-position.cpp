class Solution {
public:
    int minCostToMoveChips(vector<int>& position) {
        //if we move by 2 then cost is 0 and if its 1 then 1
        //once u know the intuituion behind this problem this is very straigthforward cause u only care about the number of even and odd chips

        int oddCount = 0, evenCount = 0;

        for(int pos : position){
            if(pos % 2){
                oddCount++;
            }else{
                evenCount++;
            }
        }

        return min(oddCount, evenCount);
    }
};