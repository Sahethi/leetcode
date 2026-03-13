class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int n = words.size();
        vector<string> res;
        int i =0, j=0;
        while(i < n){
            int start = i;
            int sum = words[i].length();
            j = i+1;
            while(j < n && (sum + words[j].length() + (j-start)) <= maxWidth){
                sum += words[j].length();
                j++;
            }
            string ans = "";
            int numWords = j - start;
            int gaps = numWords-1;

            //last Line
            if(j == n || gaps == 0){
                for(int k=start; k<j; k++){
                    ans += words[k];
                    if(k < j-1) ans += " ";
                }
                ans += string(maxWidth - ans.length(), ' ');
                
            }else{  
                
                int spaces = maxWidth - sum;
                int spacesPerGroup = spaces / gaps; 
                int extraSpaces = spaces % gaps;
                for(int l=start; l<j-1; l++){
                    ans += words[l];
                    ans += string(spacesPerGroup, ' ');
                    if(extraSpaces > 0){
                        ans += " ";
                        extraSpaces--;
                    }
                }
                ans += words[j-1];
            }   
            
            res.push_back(ans);
            i=j;
        }

        return res;
    }
};