#include "bits/stdc++.h"

#define endl '\n'
using namespace std;
using ll = long long;
const int mod = 998244353;
const int inf = 0x3f3f3f3f;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    if (a[0] != n) {
        cout << "NO" << endl;
        return;
    }
    int pos = 0;
    for (int i = 0; i < a.back(); i++) if (pos >= n || n != a[pos++]) {
            cout << "NO" << endl;
            return;
        }
    for (int i = n - 2; i >= 0; i--) {
        while (i >= 0 && a[i] == a[i + 1]) i--;
        if (i == -1) break;
        for (int j = a[i + 1]; j < a[i]; j++) if (pos >= n || i + 1 != a[pos++]) {
                cout << "NO" << endl;
                return;
            }
    }
    if (pos != n) cout << "NO" << endl;
    else cout << "YES" << endl;
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
