class Solution:
    def longestMonotonicSubarray(self, nums: List[int]) -> int:
        max_increasing = 0
        len_increasing = 0
        last_num = -1
        i = 0

        while i < len(nums):
            if nums[i] <= last_num:
                max_increasing = max(max_increasing, len_increasing)
                len_increasing = 0
                last_num = -1
            else:
                last_num = nums[i]
                len_increasing += 1
                i += 1

        max_increasing = max(max_increasing, len_increasing)

        max_decreasing = 0
        len_decreasing = 0
        last_num = 51
        i = 0

        while i < len(nums):
            if nums[i] >= last_num:
                max_decreasing = max(max_decreasing, len_decreasing)
                len_decreasing = 0
                last_num = 51
            else:
                last_num = nums[i]
                len_decreasing += 1
                i += 1

        max_decreasing = max(max_decreasing, len_decreasing)

        return max(max_increasing, max_decreasing)


arr = [1]
ans = Solution.longestMonotonicSubarray(arr)
print(ans)