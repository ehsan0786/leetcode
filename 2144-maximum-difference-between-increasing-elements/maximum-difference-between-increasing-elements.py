class Solution:
    def maximumDifference(self, nums: list[int]) -> int:

        n = len(nums)
        ans = -1

        for i in range(n):
            for j in range(n):
                if i < j and nums[i] < nums[j]:
                    ans = max(ans,nums[j]-nums[i])
        return ans