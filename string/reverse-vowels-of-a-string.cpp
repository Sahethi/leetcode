class Solution {
public:
    string reverseVowels(string s) {

        int start=0;
        int end = s.size()-1;

        string vowels="AEIOUaeiou";
        while(start<end){
            // string::npos is returned by .find() when char is not present in given string
            while(start<end && vowels.find(s[start])==string::npos) start++;
            while(start<end && vowels.find(s[end])==string::npos) end--;
            
            swap(s[start],s[end]);
            start++;
            end--;
        }
        return s;
    }
};