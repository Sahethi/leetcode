class Solution {
    public int lengthOfLongestSubstring(String s) {
        
        int maxLength = 0;
        HashMap<Character, Integer> map = new HashMap<>();
        for(int i=0, j=0; i<s.length(); i++){
            if(map.containsKey(s.charAt(i))){
                j = Math.max(j, map.get(s.charAt(i))+1 );
            }
            map.put(s.charAt(i), i);
            maxLength = Math.max(maxLength, i - j + 1);
        }

        return maxLength;
        
        
        
        
        
        
        
        
        
        // int maxLength = 0;
        // HashMap<Character, Integer> map = new HashMap<>();
        // int left, right;

        // for(left = 0, right = 0; right < s.length(); ++right){
        //     if(map.containsKey(s.charAt(right))){
        //         left = Math.max(left, map.get(s.charAt(right)) + 1);
        //     }
        //     map.put(s.charAt(right), right);
        //     maxLength = Math.max(maxLength, right-left+1);
        // }
        // return maxLength;
    }
    
    //Brute Force
    // private boolean checkForRepeatingChars(String s){
    //     for(int i=0; i<s.length(); i++){
    //         char c = s.charAt(i);
    //         if (s.indexOf(c) != s.lastIndexOf(c)) {
    //             return true; // has repeating
    //         }
    //     }
    //     return false;
    // }
    // public int lengthOfLongestSubstring(String s) {
    //     int maxLength = 0;
    //     for(int i=0; i<s.length(); i++){
    //         for(int j=i; j<s.length(); j++){
    //             if(checkForRepeatingChars(s.substring(i, j + 1))){
    //                 break;
    //             }
    //             System.out.println(s.substring(i, j + 1));
    //             maxLength = Math.max(maxLength, s.substring(i, j + 1).length());
    //         }

    //     }
    //     return maxLength;
    // }
}