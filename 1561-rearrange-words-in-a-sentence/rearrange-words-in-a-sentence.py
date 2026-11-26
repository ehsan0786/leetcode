class Solution:
    def arrangeWords(self, text: str) -> str:

        words = text.split()
        words.sort(key=len)#IN CASE OF TIED:It maintain their original relative order(automatically).
        ans = " ".join(words)
        return ans.capitalize()