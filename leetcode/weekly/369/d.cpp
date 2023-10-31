class Solution {
public:
    int maximumPoints(vector<vector<int>>& edges, vector<int>& coins, int k) {
        int n = coins.size();
        vector<vector<int>> adj(n);
        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        
        vector<vector<int>> f(n, vector<int>(15, -1));
        auto dfs = [&](auto self, int x, int i, int pa) -> int {
            if (f[x][i] != -1) return f[x][i];
            int ans1 = (coins[x] >> i) - k;
            int ans2 = coins[x] >> (i + 1);
            for (int y : adj[x]) {
                if (y == pa) continue;
                ans1 += self(self, y, i, x);
                if (i < 14) ans2 += self(self, y, i + 1, x);
            }
            return f[x][i] = max(ans1, ans2);
        };
        
        return dfs(dfs, 0, 0, -1);
    }
};
