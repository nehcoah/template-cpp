class Solution {
public:
    int maxValue(vector<int>& nums, int k) {
        int n = nums.size();
        vector f(n + 1, vector(k + 1, vector<int>(1 << 7)));
        vector g(n + 1, vector(k + 1, vector<int>(1 << 7)));
        f[0][0][0] = g[n][0][0] = 1;
        for (int i = 0; i < n; i++) {
            // f[i + 1][0][0] = 1;
            for (int j = 0; j <= k; j++) {
                for (int x = 0; x < 1 << 7; x++) {
                    if (j < k) f[i + 1][j + 1][x | nums[i]] |= f[i][j][x];
                    f[i + 1][j][x] |= f[i][j][x];
                }
            }
        }
        for (int i = n - 1; i >= 0; i--) {
            // g[i][0][0] = 1;
            for (int j = 0; j <= k; j++) {
                for (int x = 0; x < 1 << 7; x++) {
                    if (j < k) g[i][j + 1][x | nums[i]] |= g[i + 1][j][x];
                    g[i][j][x] |= g[i + 1][j][x];
                }
            }
        }
        int ans = 0;
        for (int i = k; i + k <= n; i++) {
            for (int x = 0; x < 1 << 7; x++) {
                for (int y = 0; y < 1 << 7; y++) {
                    if (f[i][k][x] && g[i][k][y]) {
                        // cout << i << " " << x << " " << y << endl;
                        ans = max(ans, x ^ y);
                    }
                }
            }
        }
        return ans;
    }
};
