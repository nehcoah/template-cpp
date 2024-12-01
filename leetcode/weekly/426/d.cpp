class Solution {
public:
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        int n = edges1.size() + 1, m = edges2.size() + 1;
        vector<vector<int>> adj1(n), adj2(m);
        for (auto &e : edges1) {
            int u = e[0], v = e[1];
            adj1[u].push_back(v);
            adj1[v].push_back(u);
        }
        for (auto &e : edges2) {
            int u = e[0], v = e[1];
            adj2[u].push_back(v);
            adj2[v].push_back(u);
        }

        unordered_set<int> st1, st2;
        auto dfs = [&](auto self, auto &adj, auto &st, int x, int pa, int p) -> int {
            int ans = p;
            if (p) st.insert(x);
            for (int y : adj[x]) {
                if (y == pa) continue;
                ans += self(self, adj, st, y, x, !p);
            }
            return ans;
        };
        int x = dfs(dfs, adj1, st1, 0, -1, 0);
        int y = dfs(dfs, adj2, st2, 0, -1, 0);

        vector<int> ans(n);
        for (int i = 0; i < n; i++) {
            ans[i] = (st1.contains(i) ? x : n - x) + max(y, m - y);
        }
        return ans;
    }
};
