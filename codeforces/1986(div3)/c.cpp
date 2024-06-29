#include "bits/stdc++.h"
using namespace std;

//#pragma GCC optimize("O3,unroll-loops")
//#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

void solve() {
    int n, m;
    cin >> n >> m;
    string s, t;
    cin >> s;
    vector<int> idx(m);
    for (int i = 0; i < m; i++) {
        cin >> idx[i];
    }
    cin >> t;

    vector<int> cnt(26), ind(n);
    for (int i = 0; i < m; i++) {
        ind[idx[i] - 1] += 1;
        cnt[t[i] - 'a'] += 1;
    }
    for (int i = 0, j = 0; i < n; i++) {
        if (ind[i]) {
            while (cnt[j] == 0) j += 1;
            s[i] = char(j + 'a');
            cnt[j] -= 1;
        }
    }
    cout << s << endl;
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
