class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        //think of directional BFS + HashSet
        unordered_set<string> dict;
        unordered_set<string> beginSet;
        unordered_set<string> endSet;
        beginSet.insert(beginWord);
        endSet.insert(endWord);

        int steps = 1;
        for(auto word : wordList) dict.insert(word);

        //in case endword is not there in the dict
        if(dict.find(endWord) == dict.end()) return 0;

        while(!beginSet.empty() && !endSet.empty()){
            if(beginSet.size() > endSet.size()){
                swap(beginSet, endSet);
            }

            unordered_set<string> nextLevel;
            for(auto word : beginSet){
                for(int i=0; i<word.length(); i++){
                    char c = word[i];
                    for(char ch = 'a'; ch <= 'z'; ch++){
                        if(ch == c) continue;
                        word[i] = ch;
                        if(endSet.find(word) != endSet.end()) return steps+1;
                        if(dict.find(word) != dict.end()) {
                            nextLevel.insert(word);
                            dict.erase(word);
                        }
                        word[i] = c;
                    }
                }
            }
            beginSet = nextLevel;
            steps++;
        }
        

        return 0;
    }
};