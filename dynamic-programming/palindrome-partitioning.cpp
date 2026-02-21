class Solution {
private:
    vector<vector<string>> result;
    bool isPalindrome(string& s, int left, int right){
        while(left < right){
            if(s[left] != s[right]) return false;
            left++;
            right--;
        }
        return true;
    }
    void backtrack(string& s, int start, vector<string>& current){
        if(start == s.size()){
            result.push_back(current);
            return;
        }

        for(int end = start; end < s.size(); end++){
            if(isPalindrome(s, start, end)){
                current.push_back(s.substr(start, end-start+1));
                backtrack(s, end+1, current);
                current.pop_back();
            }
        }
    }
public:
    vector<vector<string>> partition(string s) {
        vector<string> current;
        backtrack(s, 0, current);
        return result;
    }
};