class Solution:
    def rotate(self, nums: list[int], k: int) -> None:
        n = len(nums)
        k %= n
        last_k = nums[-1*k:]
        first_k = nums[:-1*k]
        nums[:] = last_k + first_k
        #print(ans)
        