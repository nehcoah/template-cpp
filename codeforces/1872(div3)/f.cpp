#include "bits/stdc++.h"

#define endl '\n'
using namespace std;
using ll = long long;
const int mod = 998244353;
const int inf = 0x3f3f3f3f;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), c(n), ind(n), vis(n), ans;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i]--;
        ind[a[i]]++;
    }
    for (int i = 0; i < n; i++) cin >> c[i];
    queue<int> q;
    for (int i = 0; i < n; i++) if (ind[i] == 0) q.push(i);
    while (!q.empty()) {
        int cur = q.front(); q.pop();
        ans.push_back(cur);
        vis[cur] = 1;
        if (--ind[a[cur]] == 0) q.push(a[cur]);
    }
    for (int i = 0; i < n; i++) {
        if (vis[i]) continue;
        vector<int> cc, b;
        for (int j = i; !vis[j]; j = a[j]) {
            vis[j] = 1;
            b.push_back(j);
            cc.push_back(c[j]);
        }
        int idx = min_element(cc.begin(), cc.end()) - cc.begin();
        for (int j = 0; j < b.size(); j++) ans.push_back(b[(idx + 1 + j) % b.size()]);
    }
    for (int i = 0; i < n; i++) cout << ans[i] + 1 << " \n"[i == n - 1];
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
