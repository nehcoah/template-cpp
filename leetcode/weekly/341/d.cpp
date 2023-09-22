// https://leetcode.cn/problems/minimize-the-total-price-of-the-trips/

class Solution {
public:
    int minimumTotalPrice(int n, vector<vector<int>>& edges, vector<int>& price, vector<vector<int>>& trips) {
        int cnt[n];
        memset(cnt, 0, sizeof(cnt));
        vector<vector<int>> adj(n);
        for (auto& e : edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        for (auto& t : trips){
            int end = t[1];
            function<bool(int, int)> dfs = [&](int cur, int parent){
                if (cur == end){
                    cnt[cur] += 1;
                    return true;
                }
                for (auto x : adj[cur]) {
                    if (x != parent && dfs(x, cur)){
                        cnt[cur] += 1;
                        return true;
                    }
                }
                return false;
            };
            dfs(t[0], -1);
        }

        function<pair<int, int>(int, int)> dfs = [&](int x, int parent) -> pair<int, int> {
            int n_ha = price[x] * cnt[x];
            int ha = n_ha / 2;
            for (int y : adj[x]){
                if (y != parent){
                    auto [nh, h] = dfs(y, x);
                    n_ha += min(nh, h);
                    ha += nh;
                }
            }
            return {n_ha, ha};
        };
        auto [h1, h2] = dfs(0, -1);
        return min(h1, h2);
    }
};
