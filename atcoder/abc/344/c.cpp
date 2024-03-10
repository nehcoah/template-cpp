#include "bits/stdc++.h"

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, l, q;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cin >> m;
    vector<int> b(m);
    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }
    cin >> l;
    vector<int> c(l);
    for (int i = 0; i < l; i++) {
        cin >> c[i];
    }

    set<int> st;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int k = 0; k < l; k++) {
                st.insert(a[i] + b[j] + c[k]);
            }
        }
    }

    cin >> q;
    int x;
    while (q--) {
        cin >> x;
        cout << (st.contains(x) ? "Yes" : "No") << endl;
    }

    return 0;
}
