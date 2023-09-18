# https://leetcode.cn/problems/painting-the-walls/

class Solution:
    def paintWalls(self, cost: List[int], time: List[int]) -> int:
        n = len(cost)
        @cache
        def dfs(i, t):
            if n - i - 1 < t:
                return 0
            if i == n:
                return inf
            return min(dfs(i + 1, t - 1), dfs(i + 1, t + time[i]) + cost[i])
        return dfs(0, 0)
