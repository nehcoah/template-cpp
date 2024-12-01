class Solution {
public:
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
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

        vector<int> cnt1(n), cnt2(m);
        auto check = [&](int x, auto &adj, auto &cnt, int K) {
            queue<pair<int, int>> q;
            q.emplace(x, -1);
            int tot = 0, cur = 0;
            while (!q.empty() && cur <= K) {
                for (int i = q.size(); i; i--) {
                    auto [x, pa] = q.front(); q.pop();
                    tot += 1;
                    for (int y : adj[x]) {
                        if (y == pa) continue;
                        q.emplace(y, x);
                    }
                }
                cur += 1;
            }
            return tot;
        };
        for (int i = 0; i < n; i++) {
            cnt1[i] = check(i, adj1, cnt1, k);
        }
        for (int i = 0; i < m; i++) {
            cnt2[i] = check(i, adj2, cnt2, k - 1);
        }
        int mx = *max_element(cnt2.begin(), cnt2.end());
        vector<int> ans(n);
        for (int i = 0; i < n; i++) {
            ans[i] = cnt1[i] + mx;
        }
        return ans;
    }
};
