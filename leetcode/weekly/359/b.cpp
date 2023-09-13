// 2829
// https://leetcode.cn/problems/determine-the-minimum-sum-of-a-k-avoiding-array/description/
// constructive algorithms

class Solution {
public:
    int minimumSum(int n, int k) {
        int ans = 0, cnt = 1;
        while (n--) {
            ans += cnt++;
            if (cnt == k / 2 + 1) cnt = k;
        }
        return ans;
    }
};
