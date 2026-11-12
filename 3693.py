from typing import List


class Solution:
    @staticmethod
    def totalCost(costs, i, j):
        return costs[j - 1] + (j - i) ** 2

    def climbStairs(self, n: int, costs: List[int]) -> int:
        if n == 1:
                    return self.totalCost(costs, 0, 1)

        memo = [999999999 for _ in range(n + 1)]
        memo[0] = 0

        for i in range(0, n):
            for j in range(i + 1, i + 4):
                if j <= n:
                    memo[j] = min(memo[j], memo[i] + self.totalCost(costs, i, j))

        return memo[n]

ans = Solution.climbStairs(Solution, 2, [1,4])
print(ans)