class Solution {
public:
    int maxScore(int n, int k, vector<vector<int>>& stayScore, vector<vector<int>>& travelScore) {
        vector f(n, vector<int>(k, -1));
        auto dfs = [&](auto self, int x, int i) {
            if (i == k) return 0;
            if (f[x][i] != -1) return f[x][i];
            int ans = 0;
            ans = max(ans, self(self, x, i + 1) + stayScore[i][x]);
            for (int j = 0; j < n; j++) {
                if (x == j) continue;
                ans = max(ans, self(self, j, i + 1) + travelScore[x][j]);
            }
            return f[x][i] = ans;
        };
        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans = max(ans, dfs(dfs, i, 0));
        }
        return ans;
    }
};
