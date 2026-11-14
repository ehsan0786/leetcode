class Solution:
    def repeatedSubstringPattern(self, s: str) -> bool:

        n = len(s)
        for i in range(1,n):
            if n % i == 0:
                curr = s[:i]
                if curr *(n//i) == s:
                    return True
        return False
        