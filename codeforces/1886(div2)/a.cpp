#include "bits/stdc++.h"

using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;
    if (n < 7 || n == 9) {
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
    if (n % 3 == 0) cout << 1 << " " << 4 << " " << n - 5 << endl;
    else cout << 1 << " " << 2 << " " << n - 3 << endl; 
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

