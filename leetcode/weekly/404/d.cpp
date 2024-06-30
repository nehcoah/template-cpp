class Solution {
public:
    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        int n = edges1.size() + 1, m = edges2.size() + 1;
        vector<vector<int>> adj1(n), adj2(m);
        for (auto &e : edges1) {
            adj1[e[0]].push_back(e[1]);
            adj1[e[1]].push_back(e[0]);
        }
        for (auto &e : edges2) {
            adj2[e[0]].push_back(e[1]);
            adj2[e[1]].push_back(e[0]);
        }
        
        auto check = [&](vector<vector<int>> &adj, int s) -> pair<int, int> {
            int p = adj.size();
            queue<int> q;
            vector<int> vis(p);
            q.push(s); vis[s] = 1;
            int cnt = -1, t = -1;
            while (!q.empty()) {
                for (int i = q.size(); i; i--) {
                    int x = q.front(); q.pop();
                    t = x;
                    for (int y : adj[x]) {
                        if (!vis[y]) {
                            q.push(y);
                            vis[y] = 1;
                        }
                    }
                }
                cnt += 1;
            }
            return {t, cnt};
        };
        
        auto a = check(adj1, 0).first;
        auto x = check(adj1, a).second;
        auto b = check(adj2, 0).first;
        auto y = check(adj2, b).second;

        return max({x, y, (x + 1) / 2 + (y + 1) / 2 + 1});
    }
};
