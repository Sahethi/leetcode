class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> sToT;
        unordered_map<char, char> tToS;

        for(int i=0; i<s.size(); i++){
            char a = s[i];
            char b = t[i];

            //check if s->t
            if(sToT.count(a)){
                if(sToT[a] != b) return false;
            }

            if(tToS.count(b)){
                if(tToS[b] != a) return false;
            }

            sToT[a] = b;
            tToS[b] = a;
        }

        return true;
    }
};