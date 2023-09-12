// 2849
// https://leetcode.cn/problems/determine-if-a-cell-is-reachable-at-a-given-time/
// math
// time: O(1)
// space: O(1)

class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        if (sx == fx && sy == fy) return t != 1;
        int dis = max(abs(fx - sx), abs(fy - sy));
        return dis <= t;
    }
};
