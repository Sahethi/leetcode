class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        
        vector<int> rank(26);
        for(int i=0; i<order.size(); i++){
            rank[order[i]-'a'] = i; // h gets first index
        }

        string w1 = words[0];
        string w2 = words[1];
        int n = min(w1.size(), w2.size());

        for(int i=0; i<n; i++){
            if(w1[i] != w2[i]){
                return rank[w1[i] - 'a'] < rank[w2[i] - 'a']; 
            }
        }

        return w1.size() <= w2.size();

        return true;

    }
};