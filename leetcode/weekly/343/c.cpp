// https://leetcode.cn/problems/minimum-cost-of-a-path-with-special-roads/description/

class Solution {
    int dijkstra(vector<vector<pair<int, int>>> &g, int start, int end) {
        vector<int> dist(g.size(), INT_MAX);
        dist[start] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        pq.emplace(0, start);
        while (!pq.empty()) {
            auto[d, x] = pq.top();
            pq.pop();
            if (d > dist[x]) continue;
            for (auto& [y, wt] : g[x]) {
                int new_d = dist[x] + wt;
                if (new_d < dist[y]) {
                    dist[y] = new_d;
                    pq.emplace(new_d, y);
                }
            }
        }
        return dist[end];
    }
public:
    int minimumCost(vector<int>& start, vector<int>& target, vector<vector<int>>& specialRoads) {
        if (start == target) return 0;
        map<pair<int, int>, int> mp, dis;
        vector<pair<int, int>> in{{start[0], start[1]}, {target[0], target[1]}};
        mp[make_pair(start[0], start[1])] = 0;
        mp[make_pair(target[0], target[1])] = 1;
        int idx = 2;
        for (auto &s : specialRoads) {
            auto s1 = make_pair(s[0], s[1]), s2 = make_pair(s[2], s[3]);
            if (mp.count(s1) == 0) mp[s1] = idx++, in.emplace_back(s1);
            if (mp.count(s2) == 0) mp[s2] = idx++, in.emplace_back(s2);
            if (dis.count(make_pair(mp[s1], mp[s2])) == 0) dis[make_pair(mp[s1], mp[s2])] = s[4];
            else dis[make_pair(mp[s1], mp[s2])] = min(dis[make_pair(mp[s1], mp[s2])], s[4]);
        }
        vector<vector<pair<int, int>>> adj(mp.size());
        for (int i = 0; i < mp.size(); i++) {
            for (int j = i + 1; j < mp.size(); j++) {
                auto p1 = make_pair(i, j), p2 = make_pair(j, i);
                if (dis.count(p1)) adj[i].emplace_back(j, dis[p1]);
                if (dis.count(p2)) adj[j].emplace_back(i, dis[p2]);
                int cur = abs(in[i].first - in[j].first) + abs(in[i].second - in[j].second);
                adj[i].emplace_back(j, cur);
                adj[j].emplace_back(i, cur);
            }
        }
        return dijkstra(adj, 0, 1);
    }
};
