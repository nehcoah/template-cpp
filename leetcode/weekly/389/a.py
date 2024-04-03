class Solution:
    def isSubstringPresent(self, s: str) -> bool:
        for x, y in pairwise(s):
            cur = x + y
            if cur in s and cur in s[::-1]:
                return True
        return False
