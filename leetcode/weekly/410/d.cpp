class Solution {
public:
    int countOfPairs(vector<int>& nums) {
        const int mod = 1e9 + 7;
        int n = nums.size();
        int mx = *max_element(nums.begin(), nums.end());
        vector<vector<int>> f(n, vector<int>(mx + 1)), g(n, vector<int>(mx + 1));
        for (int i = 0; i < nums[0] + 1; i++) {
            f[0][i] = 1;
        }
        g[0][0] = f[0][0];
        for (int i = 1; i <= mx; i++) {
            g[0][i] = (g[0][i - 1] + f[0][i]) % mod;
        }
        for (int i = 1; i < n; i++) {
            for (int x = 0; x <= nums[i]; x++) {
                int y = min(x, x + nums[i - 1] - nums[i]);
                if (y >= 0) f[i][x] = g[i - 1][y];
            }
            g[i][0] = f[i][0];
            for (int j = 1; j <= mx; j++) {
                g[i][j] = (g[i][j - 1] + f[i][j]) % mod;
            }
        }
        return g[n - 1][mx];
    }
};
