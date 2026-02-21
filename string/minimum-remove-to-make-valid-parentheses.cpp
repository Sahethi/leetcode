class Solution {
public:
    string minRemoveToMakeValid(string s) {
        string result;
        stack<int> st;  
        vector<bool> remove(s.size(), false);

        for(int i=0; i<s.size(); i++){
            if(s[i] == '(') {
                st.push(i);
            } else if(s[i] == ')') {
                //compare both the parentheses
                if(!st.empty())
                    st.pop();
                else
                    remove[i] = true;
            }
        }

        //basically pushing invalid parentheses
        while(!st.empty()){
            remove[st.top()] = true;
            st.pop();
        }

        for(int i=0; i<s.size(); i++){
            //take all the valid characters
            if(!remove[i])
                result += s[i];
        }

        return result;
    }
};