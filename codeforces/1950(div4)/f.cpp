#include "bits/stdc++.h"

using namespace std;
using ll = long long;

void solve() {
    int a, b, c;
    cin >> a >> b >> c;
    int n = a + b + c;
    if (2 * a + b != n - 1) {
        cout << -1 << endl;
        return;
    }
    queue<int> q;
    q.push(0);
    int ans = 0;
    while (!q.empty()) {
        int x = q.front(); q.pop();
        ans = x;
        if (a) {
            a -= 1;
            q.push(x + 1), q.push(x + 1);
        } else if (b) {
            b -= 1;
            q.push(x + 1);
        }
    }
    cout << ans << endl;
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
