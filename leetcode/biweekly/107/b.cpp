// https://leetcode.cn/problems/construct-the-longest-new-string/

class Solution {
public:
    int longestString(int x, int y, int z) {
        int mn = min(x, y), ans = z + mn * 2;
        x -= mn;
        y -= mn;
        if (x || y) ans++;
        return ans * 2;
    }
};
