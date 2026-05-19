class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        
        unordered_map<int, int> valueAndPos;
        int n = row.size();
        for(int i=0; i<n; i++){
            valueAndPos[row[i]] = i;
        }
        int swaps = 0;
        for(int i=0; i<n; i+=2){
            int x = row[i];
            int partner = x ^ 1;
            if(row[i+1] == partner) continue;
            int partnerIdx = valueAndPos[partner];

            swap(row[i+1], row[partnerIdx]);
            int A = row[i+1];
            valueAndPos[partner] = i+1;
            valueAndPos[A] = partnerIdx;

            swaps++;
        }

        return swaps;
    }
};