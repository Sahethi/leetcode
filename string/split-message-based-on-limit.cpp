class Solution {
private:
    bool canSplit(string &message, int limit, int k) {
        int n = message.length();
        int used = 0;

        int digitInK = to_string(k).size();

        int start = 1;
        int d = 1;

        while(start <= k){
            int end = min(k, start*10 - 1);
            int count = end - start + 1;

            int suffixLen = d + digitInK + 3;
            int available = limit - suffixLen;

            if(available <= 0) return false;

            used += count * available;

            start *= 10;
            d++;
        }
        return used >= n;
    }
    
    vector<string> buildResult(string &message, int limit, int k) {
        vector<string> res;
        int idx = 0;
        int n = message.length();

        for (int i = 1; i <= k; i++) {
            int suffixLen = to_string(i).size() + to_string(k).size() + 3;
            int available = limit - suffixLen;

            // take up to 'available' characters
            string part = message.substr(idx, available);
            idx += part.length();

            // add suffix
            part += "<" + to_string(i) + "/" + to_string(k) + ">";
            res.push_back(part);
        }

        return res;
    }
public:
    vector<string> splitMessage(string message, int limit) {
        
        for (int k = 1; k <= message.length(); k++) {
            if (canSplit(message, limit, k)) {
                return buildResult(message, limit, k);
            }
        }
        return {};
    }
};