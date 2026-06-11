class Solution {
public:
    int longestValidParentheses(string s) {
        
        int maxLen = 0;
        stack<int> st;

        st.push(-1);

        for(int i=0; i<s.length(); i++){
            if(s[i] == '('){
                st.push(i);
            }else{
                // char top = st.top();
                st.pop();
                if(st.empty()){
                    st.push(i);
                }else{
                    //if not empty
                    maxLen = max(maxLen, i - st.top());
                }
            }
        }

        return maxLen;
    }
};