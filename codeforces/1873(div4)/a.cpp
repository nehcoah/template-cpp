#include "bits/stdc++.h"

using namespace std;
using ll = long long;
const int mod = 998244353;

void solve() {
    string s;
    cin >> s;
    if (s == "abc") {
        cout << "YES" << endl;
        return;
    }
    for (int i = 0; i < 3; i++) {
        for (int j = i + 1; j < 3; j++) {
            string a = s;
            swap(a[i], a[j]);
            if (a == "abc") {
                cout << "YES" << endl;
                return;
            }
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
