// 2787
// https://leetcode.cn/problems/ways-to-express-an-integer-as-sum-of-powers/description/
// dp

long long cnt[301][6];
const int mod = 1e9 + 7;
auto init = []() {
    memset(cnt, 0, sizeof(cnt));
    for (int i = 1; i < 6; i++) cnt[0][i] = 1;
    for (int x = 1; x < 6; x++) {
        for (int i = 1; pow(i, x) < 301; i++) {
            int cur = pow(i, x);
            for (int j = 300; j >= cur; j--) cnt[j][x] += cnt[j - cur][x];
        }
    }
    return 0;
}();

class Solution {
public:
    int numberOfWays(int n, int x) {
        return cnt[n][x] % mod;
    }
};
