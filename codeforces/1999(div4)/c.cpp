#include "bits/stdc++.h"
using namespace std;

using ll = long long;
using ull = unsigned long long;
using u32 = unsigned;

void solve() {
    int n, s, m;
    cin >> n >> s >> m;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second;
    }
    a.emplace_back(0, 0);
    a.emplace_back(m, m);
    sort(a.begin(), a.end());
    for (int i = 0; i < a.size() - 1; i++) {
        if (a[i + 1].first - a[i].second >= s) {
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
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

