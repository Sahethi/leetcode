class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        vector<vector<string>> result;
        sort(products.begin(), products.end());
        string prefix = "";

        for(char c : searchWord){
            prefix += c;
            auto it = lower_bound(products.begin(), products.end(), prefix);
            int idx = it - products.begin();

            vector<string> topThreeStrings;
            int topThree = 0;
            for(int i=idx; i<products.size(); i++){
                topThree++;
                topThreeStrings.push_back(products[i]);
                if(topThree == 3) break;
            }
            result.push_back(topThreeStrings);
        }

        return result;
    }
};