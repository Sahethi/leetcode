class Solution {
public:
    string multiply(string num1, string num2) {

        if(num1 == "0" || num2 == "0") return "0";

        int m = num1.length();
        int n = num2.length();

        vector<int> res(m+n, 0);

        for(int i=m-1; i>=0; i--){
            for(int j=n-1; j>=0; j--){
                int digit1 = num1[i] - '0';
                int digit2 = num2[j] - '0';

                int prod = digit1 * digit2;

                int pos2 = i + j + 1; //basically the ones place
                int pos1 = i + j; //for carry

                int sum = prod + res[pos2]; // we are adding up the sums

                res[pos2] = sum %10; //keeps 1s digit
                res[pos1] += sum / 10; // keeps carry that goes left
            }
        }

        string ans; 
        int i=0;

        while(i<res.size() && res[i] == 0){ i++; }

        for(; i<res.size(); i++){
            ans.push_back(res[i] + '0');

        }
        return ans;
    }
};