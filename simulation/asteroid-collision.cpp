class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        /**
        // 5 -> 10 -> -5 and top is + ve and aane wala -ve 
        // then -5 will explore

        5 and 10 remain 

        push 8 and push -8 pop -8 and 8 they both explode as the same 

        push 10 and 2 and -5 
        collide -5 and 2 5 is the bigger one hence 2 wille explode
        hence 10 and -5 then only 10 will remain
        */

        stack<int> st;

        for(int a : asteroids){
            bool destroyed = false;

            while(!st.empty() && st.top() > 0 && a < 0){
                if(abs(st.top()) < abs(a)){
                    st.pop(); // top explodes
                    continue;
                } else if (abs(st.top()) == abs(a)){
                    st.pop(); //both explode
                }
                destroyed = true;
                break;
            }

            if(!destroyed){
                st.push(a);
            }
        }

        vector<int> res(st.size());

        for(int i=st.size()-1; i>=0; i--){
            res[i] = st.top();
            st.pop();
        }

        return res;
    }
};