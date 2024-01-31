#include "bits/stdc++.h"

using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;
    vector<pair<int, int>> x(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i].first;
    }
    for (int i = 0; i < n; i++) {
        cin >> x[i].second;
    }
    sort(x.begin(), x.end());
    for (int i = 0; i < n; i++) {
        cout << x[i].first << " \n"[i == n - 1];
    }
    for (int i = 0; i < n; i++) {
        cout << x[i].second << " \n"[i == n - 1];
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
