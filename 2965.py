from typing import List

class Solution:
    def findMissingAndRepeatedValues(self, grid: List[List[int]]) -> List[int]:
        hasAppeared = []

        for i in range(len(grid) * len(grid)):
            hasAppeared.append(0)

        for i in range(len(grid)):
            for j in range(len(grid[0])):
                hasAppeared[grid[i][j] - 1] += 1

        repeated = -1
        missing = -1

        for i in range(len(hasAppeared)):
            if hasAppeared[i] > 1:
                repeated = i + 1
            if hasAppeared[i] == 0:
                missing = i + 1

        return [repeated, missing]
    
print(Solution().findMissingAndRepeatedValues([[9,1,7],[8,9,2],[3,4,6]]))    
print(Solution().findMissingAndRepeatedValues([[1,3],[2,2]]))    