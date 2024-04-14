class Solution {
public:
    vector<int> minimumTime(int n, vector<vector<int>>& edges, vector<int>& disappear) {
        vector<vector<pair<int, int>>> adj(n);
        for (auto &e : edges) {
            adj[e[0]].emplace_back(e[1], e[2]);
            adj[e[1]].emplace_back(e[0], e[2]);
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        vector<int> ans(n, -1);
        pq.emplace(0, 0);
        while (!pq.empty()) {
            auto [d, x] = pq.top(); pq.pop();
            if (ans[x] != -1) continue;
            if (disappear[x] <= d) continue;
            ans[x] = d;
            for (auto [y, w] : adj[x]) {
                pq.emplace(d + w, y);
            }
        }
        return ans;
    }
};
