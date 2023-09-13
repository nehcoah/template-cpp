// 2836
// https://leetcode.cn/problems/maximize-value-of-function-in-a-ball-passing-game/
// binary lifting

class Solution {
public:
    long long getMaxFunctionValue(vector<int>& receiver, long long k) {
        int n = receiver.size(), f[n][35];
        long long w[n][35];
        for (int i = 0; i < n; i++) f[i][0] = receiver[i], w[i][0] = i;
        for (int j = 1; j < 35; j++) {
            for (int i = 0; i < n; i++) {
                f[i][j] = f[f[i][j - 1]][j - 1];
                w[i][j] = w[i][j - 1] + w[f[i][j - 1]][j - 1];
            }
        }
        long long ans = 0;
        for (int i = 0; i < n; i++) {
            long long cur = 0;
            int pos = i;
            for (int j = 0; j < 35; j++) {
                if ((k >> j) & 1) {
                    cur += w[pos][j];
                    pos = f[pos][j];
                }
            }
            ans = max(ans, cur + pos);
        }
        return ans;
    }
};
