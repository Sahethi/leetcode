class Solution {
private:
    vector<string> result;
    void backtrack(int n, string& curr, int open, int close){
        if(curr.length() == 2*n){
            result.push_back(curr);
            return;
        } // form 1 combination

        if(open < n){   
            curr.push_back('(');
            backtrack(n, curr, open+1, close);
            curr.pop_back();
        }   
        if(close < open){   
            curr.push_back(')');
            backtrack(n, curr, open, close+1);
            curr.pop_back();
        }   
    }
public:
    vector<string> generateParenthesis(int n) {
        string curr = "";
        backtrack(n, curr, 0, 0);
        return result;
    }
};