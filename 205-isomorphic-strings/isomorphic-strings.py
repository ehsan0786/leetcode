class Solution:
    def isIsomorphic(self, s: str, t: str) -> bool:
        mapping = {}
        used = set()
        valid = True
        if len(s) != len(t):
            valid = False
        else:
            for a, b in zip(s, t):
                if a in mapping:
                    if mapping[a] != b:
                        valid = False
                        break
                else:
                    if b in used:
                        valid = False
                        break
                    mapping[a] = b
                    used.add(b)
        if valid == True:
            return True
        return False;