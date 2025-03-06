from typing import List

class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        # Ensure nums1 is the smaller array
        if len(nums1) > len(nums2):
            nums1, nums2 = nums2, nums1
        
        x, y = len(nums1), len(nums2)
        low, high = 0, x
        
        while low <= high:
            partition1 = (low + high) // 2
            partition2 = (x + y + 1) // 2 - partition1
            
            # Edge cases for left and right boundaries
            maxLeft1 = float('-inf') if partition1 == 0 else nums1[partition1 - 1]
            minRight1 = float('inf') if partition1 == x else nums1[partition1]
            
            maxLeft2 = float('-inf') if partition2 == 0 else nums2[partition2 - 1]
            minRight2 = float('inf') if partition2 == y else nums2[partition2]
            
            # Check if we have found the correct partition
            if maxLeft1 <= minRight2 and maxLeft2 <= minRight1:
                if (x + y) % 2 == 0:
                    return (max(maxLeft1, maxLeft2) + min(minRight1, minRight2)) / 2
                else:
                    return max(maxLeft1, maxLeft2)
            elif maxLeft1 > minRight2:
                # Move partition1 to the left
                high = partition1 - 1
            else:
                # Move partition1 to the right
                low = partition1 + 1
        
        raise ValueError("Input arrays are not sorted!")
