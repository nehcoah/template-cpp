class Solution {
public:
    vector<vector<int>> constructGridLayout(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for (auto &e : edges) {
            int u = e[0], v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> cnt(5);
        vector<unordered_set<int>> id(5);
        for (int i = 0; i < n; i++) {
            cnt[adj[i].size()] += 1;
            id[adj[i].size()].insert(i);
        }

        // for (int i = 0; i < 5; i++) {
        //     cout << cnt[i] << " \n"[i == 4];
        // }

        auto check = [&](int s, int e, int d) -> vector<int> {
            assert(id[2].count(s) && id[2].count(e));
            vector<int> cur{s}, r, vis(n);
            vis[s] = 1;
            auto dfs = [&](auto self, int x, int pa) {
                if (cur.size() > d) return;
                if (x == e) {
                    if (cur.size() == d) r = cur;
                    return;
                }
                for (int y : adj[x]) {
                    if (y == pa || vis[y] || adj[y].size() == 4) continue;
                    vis[y] = 1;
                    cur.push_back(y);
                    self(self, y, x);
                    cur.pop_back();
                    vis[y] = 0;
                }
            };
            dfs(dfs, s, -1);
            return r;
        };
        
        assert(cnt[0] == 0);
        if (cnt[1] == 2) {
            assert(cnt[3] == 0 && cnt[4] == 0);
            vector<vector<int>> ans(1, vector<int>(n, -1));
            for (int i = 0, x = *id[1].begin(); i < n; i++) {
                ans[0][i] = x;
                if (i == n - 1) break;
                x = i == 0 ? adj[x][0] : (adj[x][0] == ans[0][i - 1] ? adj[x][1] : adj[x][0]);
            }
            return ans;
        } else if (cnt[2] == 4) {
            assert(cnt[1] == 0);
            int p = *id[2].begin();
            unordered_set<int> used;
            vector<pair<int, int>> dis;
            vector<int> vis(n);
            queue<pair<int, int>> q;
            q.emplace(1, p);
            vis[p] = 1;
            while (!q.empty()) {
                auto [d, x] = q.front(); q.pop();
                if (adj[x].size() == 2) {
                    dis.emplace_back(d, x);
                }
                for (int y : adj[x]) {
                    if (vis[y]) continue;
                    q.emplace(d + 1, y);
                    vis[y] = 1;
                }
            }
            assert(dis.size() == 4);
            auto [h, p1] = dis[1];
            auto [w, p2] = dis[2];
            // cout << h << " " << w << endl;
            assert(cnt[3] == 2 * (h - 2) + 2 * (w - 2));
            assert(cnt[4] == (h - 2) * (w - 2));
            if (h == 2 || w == 2) {
                if (w == 2) {
                    swap(h, w);
                    swap(p1, p2);
                }
                vector<vector<int>> ans(h, vector<int>(w, -1));
                ans[0][0] = p, ans[1][0] = p1;
                unordered_set<int> used{p, p1};
                for (int i = 1; i < w; i++) {
                    int x = ans[0][i - 1], y = ans[1][i - 1];
                    for (int X : adj[x]) {
                        if (used.count(X)) continue;
                        for (int Y : adj[y]) {
                            if (used.count(Y)) continue;
                            ans[0][i] = X, ans[1][i] = Y;
                            used.insert(X), used.insert(Y);
                        }
                    }
                }
                return ans;
            } else {
                vector<vector<int>> ans(h, vector<int>(w, -1));
                auto a = check(p, p1, h);
                auto b = check(p, p2, w);
                for (int x : a) used.insert(x);
                for (int x : b) used.insert(x);
                for (int i = 0; i < a.size(); i++) {
                    ans[i][0] = a[i];
                }
                for (int i = 0; i < b.size(); i++) {
                    ans[0][i] = b[i];
                }

                int s = -1;
                for (auto it = id[2].begin(); it != id[2].end(); it++) {
                    if (*it != ans[0][0] && *it != ans[0][w - 1] && *it != ans[h - 1][0]) {
                        s = *it;
                        break;
                    }
                }
                auto c = check(s, p1, w);
                auto d = check(s, p2, h);
                for (int x : c) used.insert(x);
                for (int x : d) used.insert(x);
                for (int i = 0; i < d.size(); i++) {
                    ans[d.size() - i - 1][w - 1] = d[i];
                }
                for (int i = 0; i < c.size(); i++) {
                    ans[h - 1][c.size() - i - 1] = c[i];
                }

                for (int i = 1; i < h - 1; i++) {
                    for (int j = 1; j < w - 1; j++) {
                        int x = ans[i - 1][j], y = ans[i][j - 1];
                        int cur = -1;
                        for (int X : adj[x]) {
                            if (used.count(X)) continue;
                            for (int Y : adj[y]) {
                                if (used.count(Y)) continue;
                                if (X == Y) {
                                    cur = X;
                                }
                            }
                        }
                        assert(cur != -1);
                        ans[i][j] = cur;
                        used.insert(cur);
                    }
                }
                return ans;
            }
        }

        return {};
    }
};
