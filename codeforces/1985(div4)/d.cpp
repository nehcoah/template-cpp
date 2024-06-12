#include "bits/stdc++.h"

//#pragma GCC optimize("O3,unroll-loops")
//#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

using namespace std;
using ll = long long;

void solve() {
    int m, n;
    cin >> m >> n;
    vector<string> s(m);
    for (int i = 0; i < m; i++) {
        cin >> s[i];
    }
    int mx = 0, id = -1;
    for (int i = 0; i < m; i++) {
        int cnt = count(s[i].begin(), s[i].end(), '#');
        if (cnt > mx) {
            mx = cnt, id = i;
        }
    }
    int cnt = 0, i = 0;
    for (; i < n; i++) {
        if (s[id][i] == '#') cnt += 1;
        if (cnt == mx / 2 + 1) break;
    }
    cout << id + 1 << " " << i + 1 << endl;
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

