class Solution:
    def minOperations(self, nums: List[int]) -> int:
        n = len(nums)
        ops = 0

        for i in range(1,n):
            if nums[i] <= nums[i-1]:
                new_value = nums[i-1]+1
                ops += new_value-nums[i]
                nums[i] = new_value
        return ops