#include "bits/stdc++.h"
using namespace std;

using ll = long long;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<int> cnt(n + 1);
    for (int i = 0; i < n; i++) {
        cnt[a[i]] += 1;
    }
    cout << (any_of(cnt.begin(), cnt.end(), [](int x) {
        return x % 2 == 1;
    }) ? "YES" : "NO") << endl;
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
