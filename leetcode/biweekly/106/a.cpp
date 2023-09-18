// https://leetcode.cn/problems/check-if-the-number-is-fascinating/

class Solution {
public:
    bool isFascinating(int n) {
        int cnt[10];
        memset(cnt, 0, sizeof(cnt));
        for (char c : to_string(n)) cnt[c - '0']++;
        for (char c : to_string(2 * n)) cnt[c - '0']++;
        for (char c : to_string(3 * n)) cnt[c - '0']++;
        if (cnt[0] != 0) return false;
        for (int i = 1; i < 10; i++) if (cnt[i] != 1) return false;
        return true;
    }
};
