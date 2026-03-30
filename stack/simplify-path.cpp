class Solution {
public:
    string simplifyPath(string path) {
        /**
        Input: "/.../a/../b/c/../d/./"
        Output: "/.../b/d"
        */

        //think abotu splitting from /
        // /home / /foo /
        stringstream ss(path);
        string token;
        vector<string> st;

        while(getline(ss, token, '/')){
            if(token == "" || token == "."){
                //do nothing
            }else if(token == ".."){
                if(!st.empty()) st.pop_back();
            }else{
                st.push_back(token);
            }
        }

        string res = "/";
        for(int i=0; i<st.size(); i++){
            if(i == st.size()-1)
                res += st[i];
            else
                res += st[i] + "/";
        }
        
        return res;

    }
};