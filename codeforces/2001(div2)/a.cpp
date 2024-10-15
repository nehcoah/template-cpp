#include "bits/stdc++.h"
using namespace std;

using ll = long long;
using ull = unsigned long long;
using u32 = unsigned;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), cnt(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        cnt[a[i] - 1] += 1;
    }
    cout << n - *max_element(cnt.begin(), cnt.end()) << "\n";
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

