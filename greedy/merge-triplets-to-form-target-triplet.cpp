class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        
        bool flag_0 = false, flag_1 = false, flag_2 = false;
        for(auto& triplet : triplets){
            int index_0 = triplet[0];
            int index_1 = triplet[1];
            int index_2 = triplet[2];
            if(index_0 > target[0] || index_1 > target[1] || index_2 > target[2]) continue;
            if(index_0 == target[0]) flag_0 = true;
            if(index_1 == target[1]) flag_1 = true;
            if(index_2 == target[2]) flag_2 = true;
        }

        if(flag_0 && flag_1 && flag_2) return true;
        return false;
    }
};