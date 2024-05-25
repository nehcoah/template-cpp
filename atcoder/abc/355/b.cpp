#include "bits/stdc++.h"

//#pragma GCC optimize("O3,unroll-loops")
//#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

using namespace std;
using ll = long long;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    auto c = a;
    for (int i = 0; i < m; i++) {
        cin >> b[i];
        c.push_back(b[i]);
    }
    set<int> st{a.begin(), a.end()};
    sort(c.begin(), c.end());
    for (int i = 0; i < n + m - 1; i++) {
        if (st.contains(c[i]) && st.contains(c[i + 1])) {
            cout << "Yes\n";
            return 0;
        }
    }
    cout << "No\n";


    return 0;
}
