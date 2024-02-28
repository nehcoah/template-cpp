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
    int mn = *min_element(a.begin(), a.end());
    int cnt = count(a.begin(), a.end(), mn);
    if (cnt == 1) {
        cout << "YES\n";
    } else {
        for (int x : a) {
            if (x == mn) continue;
            if (x % mn != 0) {
                cout << "YES\n";
                return;
            }
        }
        cout << "NO\n";
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
