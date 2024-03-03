class Solution {
public:
    vector<int> countPairsOfConnectableServers(vector<vector<int>>& edges, int signalSpeed) {
        int n = edges.size() + 1;
        vector<vector<pair<int, int>>> adj(n);
        for (auto &e : edges) {
            adj[e[0]].emplace_back(e[1], e[2]);
            adj[e[1]].emplace_back(e[0], e[2]);
        }
        vector<int> ans(n);
        for (int i = 0; i < n; i++) {
            int sum = 0;
            for (auto [v, w] : adj[i]) {
                int cur = 0;
                auto dfs = [&](auto self, int x, int pa, int len) -> void {
                    if (len % signalSpeed == 0) cur += 1;
                    for (auto [y, t] : adj[x]) {
                        if (y == pa) continue;
                        self(self, y, x, len + t);
                    }
                };
                dfs(dfs, v, i, w);
                ans[i] += cur * sum, sum += cur;
            }
        }
        return ans;
    }
};
