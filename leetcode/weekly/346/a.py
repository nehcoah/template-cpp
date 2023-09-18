# https://leetcode.cn/problems/minimum-string-length-after-removing-substrings/

class Solution:
    def minLength(self, s: str) -> int:
        n = len(s)
        while True:
            s = s.replace("AB", "")
            s = s.replace("CD", "")
            cur = len(s)
            if n == cur:
                break
            n = cur
        return n
