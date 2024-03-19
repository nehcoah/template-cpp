#include "bits/stdc++.h"

using namespace std;
using ll = long long;

void solve() {
    int n, x, pos;
    cin >> n >> x;
    vector<int> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
        if (p[i] == x) pos = i;
    }
    int l = 1, r = n + 1;
    vector<int> tag(n);
    while (l + 1 < r) {
        int m = (l + r) >> 1;
        tag[m - 1] = 1;
        if (p[m - 1] <= x) l = m;
        else r = m;
    }
    if (l == pos + 1) {
        cout << 0 << endl;
    } else {
        cout << 1 << endl;
        cout << pos + 1 << " " << l << endl;
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
