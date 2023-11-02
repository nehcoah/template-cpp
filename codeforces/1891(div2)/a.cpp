#include "bits/stdc++.h"

using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    int s = 1, i = 0;
    while (i < n) {
        for (; i < n - 1 && i < s - 1; i++) {
            if (a[i] > a[i + 1]) {
                cout << "NO" << endl;
                return;
            }
        }
        i++;
        s *= 2;
    }

    cout << "YES" << endl;
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

