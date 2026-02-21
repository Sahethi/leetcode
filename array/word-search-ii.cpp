class Solution {
private: 
    struct TrieNode{
        TrieNode* children[26];
        string word;

        TrieNode(){
            for(int i=0; i<26; i++){
                children[i] = nullptr;
            }   
            word = "";
        }
    };

    void dfs(int r, int c, vector<vector<char>>& board, vector<string>& result, TrieNode* node){

        char temp = board[r][c];

        //basically not present in the Trie
        if(temp == '#' || !node->children[temp-'a']) return;

        node = node->children[temp-'a'];
        if(node->word != ""){
            result.push_back(node->word);
            node->word = "";
        }


        board[r][c] = '#';

        if(r > 0)  dfs(r-1, c, board, result, node);
        if(r < board.size()-1)  dfs(r+1, c, board, result, node);
        if(c > 0)  dfs(r, c-1, board, result, node);
        if(c < board[0].size()-1)  dfs(r, c+1, board, result, node);

        board[r][c] = temp;

    }
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        
        TrieNode* root = new TrieNode();

        for(string& w : words){
            TrieNode* curr = root;
            for(char c : w){
                if(!(curr->children[c-'a']))
                    curr->children[c-'a'] = new TrieNode();
                curr = curr->children[c-'a'];
            }
            curr->word = w;
        }

        vector<string> result;
        //go through rows and cols
        for(int i=0; i<board.size(); i++){
            for(int j=0; j<board[0].size(); j++){
                dfs(i, j, board, result, root);
            }
        }
        return result;
    }
};