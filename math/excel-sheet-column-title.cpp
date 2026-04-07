class Solution {
public:
    string convertToTitle(int columnNumber) {
        
        //I see now, think of having a base 26
        //0 se start nahi hota, it starts with 1
        //(colNumber - 1) % 26
        //when you what to get the char do A + (colNum - 1) % 26

        string res = "";
        while(columnNumber > 0){
            res += 'A' + (columnNumber - 1) % 26;
            columnNumber = (columnNumber - 1) / 26;
        }

        reverse(res.begin(), res.end());
        return res;
    }
};