class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        
        vector<int> cpy = arr;
        sort(cpy.begin(), cpy.end());

        unordered_map<int, int> rankMp;
        int rank = 1;
        for(int n : cpy){
            if(rankMp.find(n) == rankMp.end()){
                rankMp[n] = rank;
                rank++;
            }
        }

        vector<int> result;
        for(int i=0; i<arr.size(); i++){
            result.push_back(rankMp[arr[i]]);
        }

        return result;
    }
};