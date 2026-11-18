class Solution:
    def longestPrefix(self, s: str) -> str:
        n = len(s)
        ans = ""
        for i in range(1,n):
            prefix = s[:i]
            suffix = s[-i:]
            if prefix == suffix:
                ans = prefix
        return ans