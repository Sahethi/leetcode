class Solution {
public:
    bool checkValidString(string s) {
        stack<int> leftStack;
        stack<int> starStack;

        for(int i=0; i<s.size(); i++)
            if(s[i] == '*')
                starStack.push(i);
            else if(s[i] == '(')
                leftStack.push(i);
            else
                if(!leftStack.empty())
                    leftStack.pop();
                else if(!starStack.empty())
                    starStack.pop();
                else
                    return false;

        while(!leftStack.empty() &&!starStack.empty()){
            int starTop = starStack.top();
            int leftTop = leftStack.top();
            if(starTop > leftTop){
                leftStack.pop();
                starStack.pop();
            }else
                return false;
        }

        return leftStack.empty();
    }
};