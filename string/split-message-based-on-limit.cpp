class Solution {
public:
    vector<string> splitMessage(string message, int limit) {
        
        int length = message.length();

        for(int k=1; k<=length; k++){
            int used = 0;
            bool valid = true;

            for(int i=1; i<=k; i++){
                int suffixLen = to_string(i).size() + to_string(k).size() + 3;
                int diff = limit - suffixLen;

                if(diff <= 0) {
                    valid = false;
                    break;
                }

                used += diff;
            }

            if (!valid || used < length) continue;

            vector<string> res;
            int idx = 0;

            for (int i = 1; i <= k; i++) {
                int suffixLen = to_string(i).size() + to_string(k).size() + 3;
                int diff = limit - suffixLen;

                string part = message.substr(idx, diff);
                idx += part.length();

                part += "<" + to_string(i) + "/" + to_string(k) + ">";
                res.push_back(part);
            }
            return res;
        }

        return {};

    }
};