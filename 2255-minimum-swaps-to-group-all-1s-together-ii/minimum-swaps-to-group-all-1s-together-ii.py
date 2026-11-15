class Solution:
    def minSwaps(self, nums: list[int]) -> int:
        n = len(nums)
        ones = nums.count(1) #also give me the size of window where to start 

        if ones <= 1:
            return 0

        temp = nums + nums

        curr_ones = sum(nums[:ones])
        max_ones = curr_ones  # Initially

        for i in range(ones, ones + n - 1):
            curr_ones += temp[i] - temp[i - ones]
            max_ones = max(max_ones, curr_ones)

        return ones - max_ones