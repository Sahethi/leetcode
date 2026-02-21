class Solution {
    public String minWindow(String s, String t) {

        String result = "";
        if(t.length() > s.length())
            return "";

        HashMap<Character, Integer> tMap = new HashMap<>();
        HashMap<Character, Integer> sMap = new HashMap<>();

        for(char c : t.toCharArray()){
            tMap.put(c, tMap.getOrDefault(c, 0) + 1);
        }
        int need = tMap.size();
        int have = 0;
        int minLen = Integer.MAX_VALUE;

        for(int i=0, j=0; i<s.length(); i++){
            char c = s.charAt(i);
            sMap.put(c, sMap.getOrDefault(c, 0) + 1);

            //now we are writing the condition to increment have
            if(tMap.containsKey(c) && sMap.get(c).intValue() == tMap.get(c).intValue()){
                have++;
            }

            while(have == need){
                if((i - j + 1) < minLen){
                    minLen = i - j + 1;
                    result = s.substring(j, i + 1);
                }
                char remove = s.charAt(j);
                sMap.put(remove, sMap.get(remove) - 1);

                if(tMap.containsKey(remove) && sMap.get(remove).intValue() < tMap.get(remove).intValue())
                    have--;
                j++;
            }
        }

        return result;
    }
}
    //     String result = "";
    //     if (t.length() > s.length())
    //         return "";
    //     HashMap<Character, Integer> freqMap = new HashMap<>();
    //     HashMap<Character, Integer> windowMap = new HashMap<>();

    //     //calculating thr frequencies of all the characters in 't' string
    //     for(char c : t.toCharArray()){
    //         freqMap.put(c, freqMap.getOrDefault(c, 0) + 1);
    //     }
    //     int need = freqMap.size();
    //     int have = 0;
    //     int minLen = Integer.MAX_VALUE;
    //     //pointers for the window
    //     int i = 0, j = 0;

    //     for(i=0; i<s.length(); i++){
    //         char c = s.charAt(i);
    //         windowMap.put(c, windowMap.getOrDefault(c, 0) + 1);

    //         //if c is present in freqMap and 
    //         // count of element in freqMap and windowMap is same then 
    //         // we have satisfied once
    //         //it was comparing objects isleye false aa raha tha thats why convert to intValue()
    //         if(freqMap.containsKey(c) && freqMap.get(c).intValue() == windowMap.get(c).intValue()){
    //             have++;
    //         }

    //         while(have == need){
    //             //(i - j + 1) calculates the length
    //             if ((i - j + 1) < minLen) {
    //                 minLen = i - j + 1;
    //                 //i is the end
    //                 //j is the start
    //                 result = s.substring(j, i+1);
    //             }
    //             //we will remove characters from the left
    //             char charToRemove = s.charAt(j);
    //             //map mein toh hoga hence decrement as we are removing it from left
    //             windowMap.put(charToRemove, windowMap.get(charToRemove) - 1 );

    //             //basically if this char is in our goal map and after decrementing 
    //             //we realise the count is less hence have is also one less
    //             if(freqMap.containsKey(charToRemove) 
    //                 && windowMap.get(charToRemove) < freqMap.get(charToRemove)) 
    //                 have--;
    //             //moving left
    //             j++;
    //         }
    //     }

    //     return result;
    // }
// }