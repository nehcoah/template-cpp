class Solution {
public:
    vector<bool> findAnswer(int n, vector<vector<int>>& edges) {
        const int N = 5e4 + 1;
        vector<vector<pair<int, int>>> adj(n);
        int id = 0, m = edges.size();
        map<pair<int, int>, int> mp;
        for (auto &e : edges) {
            mp[{e[0], e[1]}] = mp[{e[1], e[0]}] = id++;
            adj[e[0]].emplace_back(e[1], e[2]);
            adj[e[1]].emplace_back(e[0], e[2]);
        }
        vector<long long> dis(n, -1);
        vector<bitset<N>> f(n);
        priority_queue<array<long long, 4>, vector<array<long long, 4>>, greater<>> pq;
        pq.push({0, 0, -1, -1});
        while (!pq.empty()) {
            auto [d, x, p, t] = pq.top(); pq.pop();
            if (dis[x] != -1) {
                if (dis[x] == d) f[x] |= f[t], f[x].set(p);
                else continue;
            }
            dis[x] = d;
            if (t != -1) f[x] |= f[t];
            if (p != -1) f[x].set(p);
            for (auto [y, w] : adj[x]) {
                pq.push({d + w, y, mp[{x, y}], x});
            }
        }
        vector<bool> ans(m);
        for (int i = 0; i < m; i++) {
            if (f.back().test(i)) ans[i] = true;
        }
        return ans;
    }
};


class Solution {
public:
    vector<bool> findAnswer(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int, int>>> adj(n);
        int m = edges.size();
        for (auto &e : edges) {
            adj[e[0]].emplace_back(e[1], e[2]);
            adj[e[1]].emplace_back(e[0], e[2]);
        }
        
        auto get = [&](int s) {
            vector<long long> dis(n, -1);
            priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<>> pq;
            pq.emplace(0, s);
            while (!pq.empty()) {
                auto [d, x] = pq.top(); pq.pop();
                if (dis[x] != -1) continue;
                dis[x] = d;
                for (auto [y, w] : adj[x]) {
                    pq.emplace(d + w, y);
                }
            }
            return dis;
        };
        
        auto a = get(0);
        auto b = get(n - 1);
        vector<bool> ans(m);
        if (a.back() == -1) return ans;
        for (int i = 0; i < m; i++) {
            int u = edges[i][0], v = edges[i][1], w = edges[i][2];
            if (a[u] + b[v] + w == a.back() || a[v] + b[u] + w == a.back()) {
                ans[i] = true;
            }
        }
        return ans;
    }
};
