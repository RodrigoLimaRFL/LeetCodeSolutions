class Solution:
    def minimumCost(self, cost1: int, cost2: int, costBoth: int, need1: int, need2: int) -> int:
        if costBoth > cost1 + cost2:
            return cost1 * need1 + cost2 * need2

        # Since costBoth <= than the sum of costs, it will always be worth to use when both are needed
        bothTotal = costBoth * min(need1, need2)

        if need1 > need2:
            if(costBoth < cost1):
                return bothTotal + costBoth * (need1 - need2)
            else:
                return bothTotal + cost1 * (need1 - need2)
        elif need2 > need1:
            if(costBoth < cost2):
                return bothTotal + costBoth * (need2 - need1)
            else:
                return bothTotal + cost2 * (need2 - need1)
        else:
            return bothTotal


ans = Solution.minimumCost(Solution, 1, 2, 3, 4, 5)
print(ans)