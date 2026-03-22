class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        
        vector<int> rank(26);
        for(int i=0; i<order.size(); i++){
            rank[order[i]-'a'] = i; // h gets first index
        }


        for(int i=0; i<words.size()-1; i++){
            if(!compareWords(words[i], words[i+1], rank)){
                return false;
            }
        }

        return true;
    }

    bool compareWords(string& w1, string& w2, vector<int>& rank){
        int n = min(w1.size(), w2.size());

        for(int i=0; i<n; i++){
            if(w1[i] != w2[i]){
                return rank[w1[i] - 'a'] < rank[w2[i] - 'a']; 
            }
        }

        return w1.size() <= w2.size();
    }
};