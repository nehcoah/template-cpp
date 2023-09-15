# 2788
# https://leetcode.cn/problems/split-strings-by-separator/description/
# brute force

class Solution:
    def splitWordsBySeparator(self, words: List[str], separator: str) -> List[str]:
        ans = []
        for w in words:
            s = w.split(separator)
            for ss in s:
                if ss == '':
                    continue
                else:
                    ans.append(ss)
        return ans
