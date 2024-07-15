#include "bits/stdc++.h"
using namespace std;

using ll = long long;

void solve() {
    vector<int> a(3);
    cin >> a[0] >> a[1] >> a[2];
    for (int i = 0; i < 5; i++) {
        sort(a.begin(), a.end());
        a[0] += 1;
    }
    cout << a[0] * a[1] * a[2] << endl;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
