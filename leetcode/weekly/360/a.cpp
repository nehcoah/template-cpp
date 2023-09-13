// 2833
// https://leetcode.cn/problems/furthest-point-from-origin/description/
// brute force

class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int cnt = 0, pos = 0;
        for (char c : moves) {
            if (c == 'L') pos--;
            else if (c == 'R') pos++;
            else cnt++;
        }
        return abs(pos) + cnt;
    }
};
