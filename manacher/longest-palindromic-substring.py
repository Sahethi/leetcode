class Solution:
    #manacher solution 
    def longestPalindrome(self, s: str) -> str:
        t = "#" + "#".join(s) + "#"
        n = len(t)
        c = r = 0
        p = [0] * n #initialiing array of n as 0

        for i in range(n):
            mirror = 2 * c - i
            if i < r:
                p[i] = min(r - i, p[mirror])

            while (
                i + 1 + p[i] < n
                and i - 1 - p[i] >= 0 
                and t[i + 1 + p[i]] 
                == t[i - 1 - p[i]]
                ):
                p[i] +=1

            if i + p[i] > r:
                c = i
                r = i + p[i]

        max_len = max(p)
        center_index = p.index(max_len)
        start_index = (center_index - max_len) // 2
        longest_palindrome = s[start_index : start_index + max_len]

        return longest_palindrome



    # #DP solution
    # def longestPalindrome(self, s: str) -> str:
    #     if(len(s) <=1):
    #         return s

    #     maxLen = 1
    #     maxString = s[0]
    #     dp = [[False for _ in range(len(s))] for _ in range(len(s))]

    #     #end index
    #     for j in range(len(s)):
    #         dp[j][j] = True
    #         #start index
    #         for i in range(j):
    #             if s[i] == s[j] and ((j - i) <= 2 or dp[i+1][j-1]):
    #                 dp[i][j] = True
    #                 if(j - i + 1 > maxLen):
    #                     maxLen = j - i + 1
    #                     maxString = s[i : j + 1]


    #     return maxString

