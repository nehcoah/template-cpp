#include "bits/stdc++.h"

//#pragma GCC optimize("O3,unroll-loops")
//#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    int m;
    cin >> m;
    vector<int> d(m);
    multiset<int> st;
    for (int i = 0; i < m; i++) {
        cin >> d[i];
        st.insert(d[i]);
    }
    for (int i = 0; i < n; i++) {
        if (a[i] != b[i]) {
            if (!st.contains(b[i])) {
                cout << "NO\n";
                return;
            } else {
                st.extract(b[i]);
            }
        }
    }
    if (find(b.begin(), b.end(), d.back()) == b.end()) cout << "NO\n";
    else cout << "YES\n";
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

