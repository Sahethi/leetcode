class Solution {
public:
    int compress(vector<char>& chars) {
        
        if(chars.size() == 1) return 1;

        int i = 0;
        int write = 0;
        while(i < chars.size()){
            int count = 1;

            while(i + 1 < chars.size() && chars[i] == chars[i+1]){
                count++;
                i++;
            }

            chars[write++] = chars[i];
            string cnt = to_string(count);
            if(count > 1){
                for(char c : cnt){
                    chars[write++]  = c;
                }
            }
            i++;
        }

        return write;
    }
};