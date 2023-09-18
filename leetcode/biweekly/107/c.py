# https://leetcode.cn/problems/decremental-string-concatenation/

class Solution:
    def minimizeConcatenatedLength(self, words: List[str]) -> int:
        n = len(words)
        @cache
        def dfs(i, s):
            if i == n:
                return 0
            cur = words[i]
            ans = dfs(i + 1, cur[0] + s[-1]) + ((len(cur) - 1) if cur[-1] == s[0] else len(cur))
            ans = min(ans, dfs(i + 1, s[0] + cur[-1]) + ((len(cur) - 1) if cur[0] == s[-1] else len(cur)))
            return ans
        return dfs(1, words[0]) + len(words[0])
