#include "bits/stdc++.h"

using namespace std;
using ll = long long;

template<typename Info>
class SparseTable {
    int n;
    vector<vector<Info>> st;
public:
    SparseTable(const vector<Info> &v) {
        n = v.size();
        if (n == 0) return;
        int maxLog = 32 - __builtin_clz(n);
        st.resize(maxLog);
        st[0] = v;
        for (int j = 1; j < maxLog; j++) {
            st[j].resize(n - (1 << j) + 1);
            for (int i = 0; i <= n - (1 << j); i++) {
                st[j][i] = st[j - 1][i] + st[j - 1][i + (1 << (j - 1))];
            }
        }
    }

    Info query(int l, int r) {
        assert(0 <= l && l <= r && r <= n - 1);
        int lg = 31 - __builtin_clz(r - l + 1);
        return st[lg][l] + st[lg][r - (1 << lg) + 1];
    }
};

struct Info {
    int x = 0;
};

Info operator+(const Info &a, const Info &b) {
    return {max(a.x, b.x)};
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    vector<Info> init(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        init[i].x = a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    for (int i = 0; i < n; i++) {
        if (a[i] > b[i]) {
            cout << "NO\n";
            return;
        }
    }
    SparseTable<Info> st(init);
    for (int i = 0, j = 0; i < n; i++) {
        while (j < n && (a[j] != b[i] || (j < i && st.query(j, i).x > b[i]))) j++;
        if (j == n || (j >= i && st.query(i, j).x > b[i])) {
            cout << "NO\n";
            return;
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

