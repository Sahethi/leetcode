class Codec {
public:

    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string encoded = "";
        for(const string& str : strs){
            encoded += to_string(str.length()) + "#" + str;
        }
        return encoded;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string> result;
        int i=0;
        while(i < s.length()){
            int j = s.find("#", i);
            int length = stoi(s.substr(i, j-i));
            i = j+1;
            result.push_back(s.substr(i, length));
            i = i + length;
        }
        return result;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));