#include "bits/stdc++.h"
using namespace std;

using ll = long long;
using ull = unsigned long long;
using u32 = unsigned;

void solve() {
    int n;
    cin >> n;
    vector<int> p(n);
    for (int i = 1; i < n; i++) {
        int x = 0;
        while (true) {
            cout << "? " << x + 1 << " " << i + 1 << endl;
            int y; cin >> y; y -= 1;
            if (x == y) break;
            x = y;
        }
        p[i] = x;
    }
    cout << "! ";
    for (int i = 1; i < n; i++) {
        cout << i + 1 << " " << p[i] + 1 << " ";
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

