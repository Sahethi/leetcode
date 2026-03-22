class Solution {
public:
    string decodeString(string s) {
        stack<pair<string, int>> st;
        string currStr = "";
        int currNum = 0;

        for(char c : s){
            if(isdigit(c)){
                currNum = currNum * 10 + (c - '0');
            } else if(isalpha(c)){
                currStr += c;
            } else if(c == '['){
                st.push({currStr, currNum});
                currStr = "";
                currNum = 0;
            } else if(c == ']'){
                auto topPair = st.top();
                st.pop();
                string temp = "";
                for(int i=0; i<topPair.second; i++){
                    temp += currStr;
                }
                currStr = topPair.first + temp;
            }
            
        }

        return currStr;
    }
};