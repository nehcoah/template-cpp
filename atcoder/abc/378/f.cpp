#include "bits/stdc++.h"
using namespace std;

using ll = long long;
using ull = unsigned long long;
using u32 = unsigned;

//template <typename K, typename V, typename Comp = std::less<K>>
//using ordered_map = __gnu_pbds::tree<
//        K, V, Comp,
//        __gnu_pbds::rb_tree_tag,
//        __gnu_pbds::tree_order_statistics_node_update
//>;
//
//template <typename K, typename Comp = std::less<K>>
//using ordered_set = ordered_map<K, __gnu_pbds::null_type, Comp>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<vector<int>> adj(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u -= 1; v -= 1;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> f(n);
    ll ans = 0;

    auto dfs = [&](auto self, int x, int pa) -> void {
        f[x] += (adj[x].size() == 2);
        for (int y : adj[x]) {
            if (y == pa) continue;
            self(self, y, x);
            ans += 1ll * f[x] * f[y];
            if (adj[x].size() == 2 && adj[y].size() == 2) {
                ans -= 1;
            }
            if (adj[x].size() == 3) {
                f[x] += f[y];
            }
        }
    };
    dfs(dfs, 0, -1);
    cout << ans << endl;

    return 0;
}

