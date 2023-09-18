// https://leetcode.cn/problems/total-distance-traveled/description/

class Solution {
public:
    int distanceTraveled(int a, int b) {
        int ans = 0;
        while (a) {
            if (a >= 5) {
                a -= 5;
                if (b > 0) a += 1, b -= 1;
                ans += 50;
            } else {
                ans += a * 10;
                break;
            }
        }
        return ans;
    }
};
