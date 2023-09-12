// 2846
// https://leetcode.cn/problems/minimum-edge-weight-equilibrium-queries-in-a-tree/description/
// lca, prefix sum

class Solution {
    vector<int> depth;
    vector<vector<int>> pa;
    vector<array<int, 26>> wt;
public:
    vector<int> minOperationsQueries(int n, vector<vector<int>>& edges, vector<vector<int>>& queries) {
        int m = 32 - __builtin_clz(n);
        vector<vector<pair<int, int>>> adj(n);
        for (auto &e : edges) {
            int x = e[0], y = e[1], w = e[2];
            adj[x].emplace_back(y, w);
            adj[y].emplace_back(x, w);
        }

        depth.resize(n);
        pa.resize(n, vector<int>(m, -1));
        wt.resize(n);

        auto dfs = [&](auto self, int x, int fa, auto &cur) -> void {
            pa[x][0] = fa;
            for (auto [y, w] : adj[x]) {
                if (y != fa) {
                    depth[y] = depth[x] + 1;
                    cur[w - 1] += 1;
                    wt[y] = cur;
                    self(self, y, x, cur);
                    cur[w - 1] -= 1;
                }
            }
        };
        array<int, 26> tmp{};
        dfs(dfs, 0, -1, tmp);

        for (int i = 0; i < m - 1; i++)
            for (int x = 0; x < n; x++)
                if (int p = pa[x][i]; p != -1) pa[x][i + 1] = pa[p][i];

        auto get = [&](int x, int y) {
            int nodex = x, nodey = y, fa;
            if (depth[x] > depth[y])
                swap(x, y);
            for (int k = depth[y] - depth[x]; k; k &= k - 1) y = pa[y][__builtin_ctz(k)];
            if (y == x) fa = x;
            else {
                for (int i = pa[x].size() - 1; i >= 0; i--) {
                    int px = pa[x][i], py = pa[y][i];
                    if (px != py) {
                        x = px;
                        y = py;
                    }
                }
                fa = pa[x][0];
            }
            int mx = 0, sum = 0;
            for (int i = 0; i < 26; i++) {
                int cur = wt[nodex][i] + wt[nodey][i] - 2 * wt[fa][i];
                sum += cur;
                mx = max(cur, mx);
            }
            return sum - mx;
        };

        vector<int> ans;
        for (auto & q : queries) {
            ans.push_back(get(q[0], q[1]));
        }
        return ans;
    }
};
