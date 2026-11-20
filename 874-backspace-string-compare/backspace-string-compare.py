class Solution:
    def solve(self,s):
        result = []
        for ch in s:
            if ch == '#':
                if result:
                    result.pop()
            else:
                result.append(ch)
        return ''.join(result)

    def backspaceCompare(self, s: str, t: str) -> bool:
        return self.solve(s) == self.solve(t)