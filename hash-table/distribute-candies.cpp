class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        //n is always even 
        unordered_set<int> uniqueEl;
        int n = candyType.size();
        for(int c : candyType){
            uniqueEl.insert(c);
        }

        int ans = n/2;
        int setSize = uniqueEl.size();
        ans = min(ans, setSize);

        return ans;
    }
};