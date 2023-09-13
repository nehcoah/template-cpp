// 2834
// https://leetcode.cn/problems/find-the-minimum-possible-sum-of-a-beautiful-array/
// constructive algorithms

class Solution {
public:
    long long minimumPossibleSum(int n, int target) {
        if (n == 1) return 1;
        long long ans = 0, cnt = 1;
        for (int i = 1; i <= target / 2 && n; i++, n--) ans += i;
        while (n--) ans += target++;
        return ans;
    }
};
