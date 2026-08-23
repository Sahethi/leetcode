class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        //n is always even 
        unordered_set<int> uniqueEl(candyType.begin(), candyType.end());
        int n = candyType.size();
        int ans = n/2;
        int setSize = uniqueEl.size();
        ans = min(ans, setSize);

        return ans;
    }
};