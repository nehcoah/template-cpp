class Solution {
public:
    int minimumCoins(vector<int>& prices) {
        int n = prices.size();
        
        vector<vector<int>> f(n + 1, vector<int>(n + 1, -1));
        auto dfs = [&](auto self, int i, int x) {
            if (i == n) return 0;
            if (f[i][x] != -1) return f[i][x];
            int ans = 1e9;
            if (x) ans = min(ans, self(self, i + 1, x - 1));
            ans = min(ans, self(self, i + 1, i + 1) + prices[i]);
            return f[i][x] = ans;
        };
        return dfs(dfs, 0, 0);
    }
};
