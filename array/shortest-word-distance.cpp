class Solution {
public:
    int shortestDistance(vector<string>& wordsDict, string word1, string word2) {
        
        int word1Index = -1, word2Index = -1;
        int n = wordsDict.size();
        int minDist = INT_MAX;
        for(int i=0; i<n; i++){
            if(wordsDict[i] == word1){
                word1Index = i;
            }
            if(wordsDict[i] == word2){
                word2Index = i;
            }

            if(word2Index != -1 && word1Index != -1){
                minDist = min(minDist, abs(word1Index - word2Index));
            }
        }

        return minDist;
    }
};