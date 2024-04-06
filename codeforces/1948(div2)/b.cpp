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
    int suf = 100;
    for (int i = n - 1; i >= 0; i--) {
        if (suf < a[i]) {
            int l = a[i] / 10;
            int r = a[i] % 10;
            if (l > r || r > suf) {
                cout << "NO\n";
                return;
            }
            suf = l;
        } else {
            suf = a[i];
        }
    }
    cout << "YES\n";
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
