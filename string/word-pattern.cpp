class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, string> charToWord;
        unordered_map<string, char> wordToChar;

        // Split s into words
        stringstream ss(s);
        vector<string> words;
        string word;

        while (ss >> word) {
            words.push_back(word);
        }

        // Number of words must match pattern length
        if (pattern.size() != words.size()) {
            return false;
        }

        // Check the mappings
        for (int i = 0; i < pattern.size(); i++) {
            char c = pattern[i];
            string w = words[i];

            // Character already maps to a different word
            if (charToWord.find(c) != charToWord.end() &&
                charToWord[c] != w) {
                return false;
            }

            // Word already maps to a different character
            if (wordToChar.find(w) != wordToChar.end() &&
                wordToChar[w] != c) {
                return false;
            }

            // Create the mappings
            charToWord[c] = w;
            wordToChar[w] = c;
        }

        return true;
    }
};