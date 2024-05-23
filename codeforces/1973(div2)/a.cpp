#include "bits/stdc++.h"

//#pragma GCC optimize("O3,unroll-loops")
//#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

using namespace std;
using ll = long long;

void solve() {
    int a, b, c;
    cin >> a >> b >> c;
    if ((a + b + c) % 2 == 1) {
        cout << -1 << endl;
        return;
    }
    priority_queue<int> pq;
    pq.push(a), pq.push(b), pq.push(c);
    int ans = 0;
    while (!pq.empty()) {
        int x = pq.top(); pq.pop();
        int y = pq.top(); pq.pop();
        if (x == 0 || y == 0) break;
        x -= 1, y -= 1;
        pq.push(x);
        pq.push(y);
        ans += 1;
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
