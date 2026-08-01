class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        
        sort(arr.begin(), arr.end());

        if(arr.size() <= 1) return true;

        int firstDist = abs(arr[0] - arr[1]);

        for(int i=1; i<arr.size()-1; i++){
            int dist = abs(arr[i] - arr[i+1]);
            if(dist == firstDist) continue;
            else return false;
        }

        return true;
    }
};