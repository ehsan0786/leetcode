class Solution:
    def eraseOverlapIntervals(self, intervals: list[list[int]]) -> int:
        intervals.sort(key = lambda x:x[1])
        last_end = float("-inf")
        cnt = 0

        for start,end in intervals:
            if start >= last_end:
                cnt += 1
                last_end = end
        return len(intervals) - cnt #non-overlapping