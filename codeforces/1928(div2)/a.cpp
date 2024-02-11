#include "bits/stdc++.h"

using namespace std;
using ll = long long;

void solve() {
    int a, b;
    cin >> a >> b;
    if (a % 2 == 0) {
        int A = a / 2;
        int B = 2 * b;
        if (A != b && B != a) {
            cout << "Yes\n";
            return;
        }
    }
    if (b % 2 == 0) {
        int A = a * 2;
        int B = b / 2;
        if (A != b && B != a) {
            cout << "Yes\n";
            return;
        }
    }
    cout << "No\n";
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
