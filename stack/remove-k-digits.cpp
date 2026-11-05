class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<int> st;
        if(num.empty()) return "0";
        if(k == 0) return num;

        string result = "";

        //push the first digit onto the stack
        st.push(num[0] - '0');

        //start iterating from the second digit
        for(int i=1; i<num.size(); i++){
            //keep a track of the current element
            int curr = num[i] - '0';

            //while my stack is not empty and k digits remain and currently my stack top which the element pushed last is more than my current element so then pop that cause its more
            //and because we have popped we register than as 1 removal so k--
            while(!st.empty() && k > 0 && st.top() > curr ){
                st.pop();
                k--;
            }
            //and push our current element
            st.push(curr);
        }

        //for example we have k remaining means we had a increaing order number hence we gotta pop from the end
        // if(k > 0){
            while(k > 0){
                st.pop();
                k--;
            }
        // }

        //pop all the elements and concatenate that to our stack
        while(!st.empty()){
            result += char(st.top() + '0');
            st.pop();
        }

        reverse(result.begin(), result.end());

        //we are trying to remove prefix zeros
        //first position that is not 0
        size_t pos = result.find_first_not_of('0');
        if(pos == string::npos) return "0";
        result = result.substr(pos);

        return result;
    }
};