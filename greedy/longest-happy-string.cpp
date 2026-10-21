class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        //atmost a appearances in a
        //similarly for b and c
        //return the longest possible happy string
        /**
        none of the occurences can be aaa bbb ccc collectively 

        a + b + c > 0
        and range of a, b, c will be <= 100

        so max we can take for each is 2
        so we sort our values according to the max .. min 
        7 1 1
        hence it would be like
        ccaccbcc
        **/

        priority_queue<pair<int, char>> vals;

        if(a > 0) vals.push({a, 'a'});
        if(b > 0) vals.push({b, 'b'});
        if(c > 0) vals.push({c, 'c'});

        string s = "";

        while(!vals.empty()){
            auto [firstCount, firstCh] = vals.top();
            vals.pop();

            int n = s.length();

            if(n >= 2 && s[n-1] == firstCh && s[n-2] == firstCh){
                //we cant use the current char as we already have 2 of them 

                if(vals.empty()) break;

                auto [secondCount, secondCh] = vals.top();
                vals.pop();

                s += secondCh;
                secondCount--;

                if(secondCount > 0) vals.push({secondCount, secondCh});

                vals.push({firstCount, firstCh});
            }else{
                s += firstCh;
                firstCount--;

                if(firstCount > 0) vals.push({firstCount, firstCh});

            }
        }

        return s;
    }
};