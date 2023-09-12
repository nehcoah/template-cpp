// 2844
// https://leetcode.cn/problems/minimum-operations-to-make-a-special-number/
// math

class Solution {
public:
    int minimumOperations(string num) {
        int n = num.size(), ans = n;
        for (char c : num) if (c == '0') ans--;
        int f = 0, g = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (num[i] == '5') f = 1;
            if (f && (num[i] == '2' || num[i] == '7')) {
                ans = min(ans, n - i - 2);
                break;
            }
        }
        f = 0, g = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (!f && num[i] == '0') {
                f = 1;
                continue;
            }
            if (f && (num[i] == '0' || num[i] == '5')) {
                ans = min(ans, n - i - 2);
                break;
            }
        }
        return ans;
    }
};
