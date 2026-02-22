class Solution {
public:
    int minFlips(string target) {
    int count = 0;
    char state = '0';
    for (char c : target) {
        if (c != state) {
            count++;
            state = c;
        }
    }
    return count;
}
};
