#include "bits/stdc++.h"

//#pragma GCC optimize("O3,unroll-loops")
//#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a(n), c(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> c[i];
    }
    vector<int> idx(n);
    iota(idx.begin(), idx.end(), 0);
    sort(idx.begin(), idx.end(), [&](int i, int j) {
        return a[i] > a[j];
    });
    set<int> st;
    int pre = 1e9 + 1;
    for (int i : idx) {
        if (pre < c[i]) continue;
        else {
            st.insert(i + 1);
            pre = c[i];
        }
    }
    cout << st.size() << endl;
    for (int x : st) {
        cout << x << " \n"[x == *st.rbegin()];
    }

    return 0;
}
