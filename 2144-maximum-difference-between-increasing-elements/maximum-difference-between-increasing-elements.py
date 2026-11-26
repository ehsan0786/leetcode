class Solution:
    def maximumDifference(self, nums: list[int]) -> int:

        # n = len(nums)
        # ans = -1

        # for i in range(n):
        #     for j in range(n):
        #         if i < j and nums[i] < nums[j]:
        #             ans = max(ans,nums[j]-nums[i])
        # return ans

        max_diff = -1 #ans
        minimum = nums[0]

        for i in range(1,len(nums)):
            max_diff = max(max_diff,nums[i]-minimum)
            minimum = min(minimum,nums[i])
        return (-1 if max_diff == 0 else max_diff)