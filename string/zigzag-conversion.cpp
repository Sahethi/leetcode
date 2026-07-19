class Solution {
public:
    string convert(string s, int numRows) {
        
        /**
        here the numRows = 3 ... hence using the index 0 1 2
        P A Y P A L I S H I R I N G
        0 1 2 1 0 1 2 1 0 1 2 1 0 1

        here numRows = 4
        P A Y P A L I S H I R I N G
        0 1 2 3 2 1 0 1 2 3 2 1 0 1

        then group all 0s together then 1s and then 2s and then 3s that our final string
        PINALSIGYAHRPI
        PINALSIGYAHRPI this works
        **/

        if(numRows == 1) return s;

        //this would create 0 1 2
        vector<string> rows(numRows);

        vector<pair<int, char>> v;
        int n = s.length();

        int dir = 1;
        int maxIdx = numRows - 1;
        int i=0;

        for(int k=0; k<n; k++){

            if(i == maxIdx){
                dir = -1;
            }else if (i == 0){
                dir = 1;
            }

            rows[i] += s[k];

            i += dir;
        }

        string target = "";

        for(auto& row : rows){
            target += row;
        }

        return target;
    }
};