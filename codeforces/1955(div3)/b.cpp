// #pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

#include "bits/stdc++.h"

using namespace std;
using ll = long long;

void solve() {
    int n, c, d;
    cin >> n >> c >> d;
    multiset<int> st;
    for (int i = 0; i < n * n; i++) {
        int a; cin >> a;
        st.insert(a);
    }
    vector<int> b(n);
    b[0] = *st.begin();
    st.erase(st.begin());
    for (int i = 1; i < n; i++) {
        int x = b[i - 1] + d;
        if (st.count(x)) b[i] = x, st.extract(x);
        else {
            cout << "NO\n";
            return;
        }
    }
    for (int i = 0; i < n; i++) {
        int pre = b[i];
        for (int j = 1; j < n; j++) {
            int x = pre + c;
            if (st.count(x)) st.extract(x), pre = x;
            else {
                cout << "NO\n";
                return;
            }
        }
    }
    cout << "YES\n";
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
