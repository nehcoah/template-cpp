#include "bits/stdc++.h"
using namespace std;

using ll = long long;
using ull = unsigned long long;
using u32 = unsigned;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    string s;
    cin >> s;
    vector<int> f(n + 1);
    vector<int> vis(n + 1);
    for (int i = 1; i <= n; i++) {
        if (vis[i]) continue;
        int cur = 0;
        vector<int> p;
        for (int x = i; !vis[x]; x = a[x]) {
            vis[x] = 1;
            cur += s[x - 1] == '0';
            p.push_back(x);
        }
        for (int x : p) {
            f[x] = cur;
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << f[i] << " \n"[i == n];
    }
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

