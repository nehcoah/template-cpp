#include "bits/stdc++.h"

using namespace std;
using ll = long long;

void solve() {
    const int inf = 0x3f3f3f3f;
    int n;
    cin >> n;
    vector<vector<int>> adj(n);
    for (int i = 1; i < n; i++) {
        int a; cin >> a;
        a--;
        adj[a].push_back(i);
    }
    string t;
    cin >> t;
    
    auto dfs = [&](auto self, int x) -> array<int, 3> {
        int c = inf, s = inf, p = inf;
        if (t[x] == 'C') c = 0;
        else if (t[x] == 'S') s = 0;
        else p = 0;

        for (auto y : adj[x]) {
            int cur_c = inf, cur_s = inf, cur_p = inf;
            auto [C, S, P] = self(self, y);
            int mn = min({C, S, P});
            
            // 不管什么情况，先造墙再说
            cur_c = min(cur_c, c + mn + 1);
            cur_s = min(cur_s, s + mn + 1);
            cur_p = min(cur_p, p + mn + 1);
            
            // 不造墙：
            // 对c来说：当前c只能和叶子节点的c合并
            // 对s来说：当前s和子节点的s或c合并，当前节点的c和子节点的s合并
            // 对p来说：当前p和子节点的p或c合并，当前节点的c和子节点的p合并
            cur_c = min(cur_c, c + C);
            cur_s = min({cur_s, s + min(C, S), c + S});
            cur_p = min({cur_p, p + min(C, P), c + P});
            
            c = cur_c, s = cur_s, p = cur_p;
        }
        return {c, s, p};
    };

    auto [c, s, p] = dfs(dfs, 0);
    cout << min({c, s, p}) << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
