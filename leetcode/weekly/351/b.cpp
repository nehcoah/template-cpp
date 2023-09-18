// https://leetcode.cn/problems/minimum-operations-to-make-the-integer-zero/

class Solution {
public:
    int makeTheIntegerZero(long long num1, long long num2) {
        for (int i = 1; i < 61; i++){
            long long n = num1 - i * num2;
            if (n < 0) continue;
            int cnt = __builtin_popcountll(n);
            if (i <= n && cnt <= i) return i;
        }
        return -1;
    }
};
