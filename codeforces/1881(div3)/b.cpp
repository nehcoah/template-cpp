#include "bits/stdc++.h"

using namespace std;
using ll = long long;

void solve() {
    vector<int> f(3);
    for (int i = 0; i < 3; i++) cin >> f[i];
    sort(f.begin(), f.end());
    int cnt = 0;
    if (f[1] % f[0] == 0) cnt += f[1] / f[0] - 1;
    else cnt = 10;
    if (f[2] % f[0] == 0 && cnt <= 3) cnt += f[2] / f[0] - 1;
    else cnt = 10;
    cout << (cnt <= 3 ? "YES" : "NO") << endl;
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

