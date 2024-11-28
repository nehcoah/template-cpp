class Solution {
public:
    long long maximizeSumOfWeights(vector<vector<int>>& edges, int k) {
        using ll = long long;
        int n = edges.size();
        vector<vector<pair<int, int>>> adj(n + 1);
        for (auto &e : edges) {
            int u = e[0], v = e[1], w = e[2];
            adj[u].emplace_back(v, w);
            adj[v].emplace_back(u, w);
        }

        auto dfs = [&](auto self, int x, int pa) -> pair<ll, ll> {
            // not choose, choose
            ll A = 0;
            vector<int> p;
            for (auto [y, w] : adj[x]) {
                if (y == pa) continue;
                auto [a, b] = self(self, y, x);
                A += a;
                if (b - a + w > 0) p.push_back(b - a + w);
            }
            sort(p.begin(), p.end(), greater());
            for (int i = 0; i < min<int>(k - 1, p.size()); i++) {
                A += p[i];
            }
            ll B = A;
            if (p.size() >= k) A += p[k - 1];
            return make_pair(A, B);
        };

        return dfs(dfs, 0, -1).first;
    }
};
