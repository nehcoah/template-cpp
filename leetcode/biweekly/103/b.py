# https://leetcode.cn/problems/find-the-prefix-common-array-of-two-arrays/

class Solution:
    def findThePrefixCommonArray(self, A: List[int], B: List[int]) -> List[int]:
        ans = []
        s1, s2 = set(), set()
        for x, y in zip(A, B):
            s1.add(x)
            s2.add(y)
            ans.append(len(s1.intersection(s2)))
        return ans
