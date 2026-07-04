class Solution {
public:
    int shortestDistance(vector<string>& wordsDict, string word1, string word2) {
        
        int word1Index, word2Index;
        int n = wordsDict.size();

        for(int i=0; i<n; i++){
            if(wordsDict[i] == word1){
                word1Index = i;
            }
            if(wordsDict[i] == word2){
                word2Index = i;
            }
        }

        return abs(word1Index - word2Index);
    }
};