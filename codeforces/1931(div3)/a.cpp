#include "bits/stdc++.h"

using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;
    vector<int> a{1, 1, n - 2};
    if (a[2] > 26) {
        a[1] += a[2] - 26;
        a[2] = 26;
    }
    if (a[1] > 26) {
        a[0] += a[1] - 26;
        a[1] = 26;
    }
    for (int i = 0; i <= 2; i++) {
        cout << char('a' + a[i] - 1);
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

