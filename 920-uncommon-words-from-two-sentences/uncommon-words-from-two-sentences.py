class Solution:
    def uncommonFromSentences(self, s1: str, s2: str) -> list[str]:
        words1 = s1.split()
        words2 = s2.split()

        freq = {}

        for word in words1+words2:
            freq[word] = freq.get(word,0) + 1

        ans = []
        for key in freq:
            if freq[key] == 1:
                ans.append(key)
        return ans