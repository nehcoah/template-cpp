#include "bits/stdc++.h"

using namespace std;
using ll = long long;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> b(n);
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    int s = 2023;
    for (int i = 0; i < n; i++) {
        if (s % b[i] != 0) {
            cout << "NO" << endl;
            return;
        }
        s /= b[i];
    }
    cout << "YES" << endl;
    cout << s;
    for (int i = 1; i < k; i++) {
        cout << " 1";
    }
    cout << endl;
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

