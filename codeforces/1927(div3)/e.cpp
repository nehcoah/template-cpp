#include "bits/stdc++.h"

using namespace std;
using ll = long long;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> ans(n);
    int l = 1, r = n;
    for (int i = 0; i < k; i++) {
        for (int j = i; j < n; j += k) {
            ans[j] = i & 1 ? r-- : l++;
        }
    }
    for (int i = 0; i < n; i++) {
        cout << ans[i] << " \n"[i == n - 1];
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
