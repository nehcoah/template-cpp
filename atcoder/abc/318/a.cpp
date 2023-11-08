#include "bits/stdc++.h"

using namespace std;
using ll = long long;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, p;
    cin >> n >> m >> p;
    int ans = 0;
    for (int x = m; x <= n; x += p) {
        ans++;
    }
    cout << ans << endl;

    return 0;
}

