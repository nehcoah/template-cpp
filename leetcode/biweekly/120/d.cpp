class Solution {
public:
    vector<long long> placedCoins(vector<vector<int>>& edges, vector<int>& cost) {
        int n = edges.size() + 1;
        vector<vector<int>> adj(n);
        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        
        vector<long long> ans(n, 1);
        auto dfs = [&](auto self, int x, int pa) -> pair<multiset<int>, multiset<int>> {
            multiset<int> pos, neg;
            if (cost[x] > 0) pos.insert(cost[x]);
            else neg.insert(cost[x]);
            for (int y : adj[x]) {
                if (y == pa) continue;
                auto [po, ne] = self(self, y, x);
                for (int z : po) {
                    pos.insert(z);
                    if (pos.size() > 3) pos.erase(pos.begin());
                }
                for (int z : ne) {
                    neg.insert(z);
                    if (neg.size() > 3) neg.erase(prev(neg.end()));
                }
            }
            if (pos.size() + neg.size() >= 3) {
                long long cur = numeric_limits<long long>::min();
                if (pos.size() == 3) {
                    long long t = 1;
                    for (int z : pos) t *= z;
                    cur = max(cur, t);
                }
                if (neg.size() >= 2 && !pos.empty()) {
                    long long t = *neg.begin() * *(next(neg.begin()));
                    t *= *pos.rbegin();
                    cur = max(cur, t);
                }
                ans[x] = cur > 0 ? cur : 0;
            }
            return {pos, neg};
        };
        
        dfs(dfs, 0, -1);
        return ans;
    }
};
