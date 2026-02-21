class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        
        for(string token: tokens){
            int res = 0;
            if(token == "+" || token == "-" || token == "*"  || token == "/"){
                int right = st.top();
                st.pop();
                int left = st.top();
                st.pop();

                if(token == "+") res = left + right;
                else if(token == "-") res = left - right;
                else if(token == "*") res = left * right;
                else res = left / right;

                st.push(res);
            }else{
                st.push(stoi(token));
            }
        }
        return st.top();
    }
};