#include "bits/stdc++.h"

using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), v(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        v[a[i]] += 1;
    }
    int f = 0;
    for (int i = 0; i < n; i++) {
        if (v[i] == 0) {
            cout << i << endl;
            return;
        }
        if (v[i] == 1) {
            if (f == 0) f = 1;
            else {
                cout << i << endl;
                return;
            }
        }
    }
    cout << n << endl;
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
