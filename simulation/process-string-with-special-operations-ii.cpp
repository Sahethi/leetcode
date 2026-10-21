class Solution {
public:
    char processStr(string s, long long k) {
        vector<long long> lengths(s.size());

        //basically the length of the string can be overshot given 
        // the index can be requested in long long too
        //so the length of the string after processing each character check that
        // and store it in the vector
        long long len = 0;
        for(int i=0; i<s.size(); i++){
            char c = s[i];
            if(c >= 'a' && c <= 'z'){
                len++;
            } else if (c == '*'){
                if(len > 0) len--;
            } else if (c == '#'){
                len = 2 * len;
            } else if (c == '%'){
                //do nothing
            }
            lengths[i] = len;
        }
        
    
        if(k >= len){
            return '.';
        }
        
        for(int i=s.size()-1; i>=0; i--){
            char c = s[i];
            long long len = (i > 0) ? lengths[i-1] : 0;
            if(c >= 'a' && c <= 'z'){
                 if(k == lengths[i]-1) return c;

            } else if (c == '#'){
                if(k >= len){
                    k = k - len;
                }
            } else if (c == '%'){
                k = lengths[i] - 1 - k;
            } else if (c == '*'){

            }
        }

        return '.';
    }
};