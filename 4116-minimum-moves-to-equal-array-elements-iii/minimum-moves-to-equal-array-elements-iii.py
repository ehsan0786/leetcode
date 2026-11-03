class Solution:
    def minMoves(self, nums: List[int]) -> int:
        n = len(nums)
        maxi = float("-inf")
        for x in nums:
            maxi = max(maxi,x)

        moves = 0
        for x in nums:
            moves += maxi-x
        return moves