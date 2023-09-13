#include "bits/stdc++.h"

#define endl '\n'
using namespace std;
using ll = long long;
const int mod = 998244353;
const int inf = 0x3f3f3f3f;

void solve() {
    string a, b;
    cin >> a >> b;
    if (a == b) {
        cout << "YES" << endl;
        return;
    }
    for (int i = 0; i < a.size() - 1; i++) {
        if (a[i] == '0' && b[i] == '0' && a[i + 1] == '1' && b[i + 1] == '1') {
            cout << "YES" << endl;
            return;
        }
    }
    cout << "NO" << endl;
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
