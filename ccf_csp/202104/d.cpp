// 60

#include "bits/stdc++.h"

using namespace std;
using ll = long long;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    const int mod = 1e9 + 7;

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    unordered_set<int> st;
    auto check = [&](int i, int j) {
        if (a[i] + 1 == a[j]) return 0;
        int d = a[j] - a[i], ans = st.empty();
        for (int x = 2; x * x <= d; x++) {
            if (d % x == 0) {
                bool good = true;
                for (int y = a[i] + x; y < a[j]; y += x) {
                    if (st.count(y)) {
                        good = false;
                        break;
                    }
                }
                if (good) ans++;
                if (x * x == d) break;
                good = true;
                for (int y = a[i] + d / x; y < a[j]; y += d / x) {
                    if (st.count(y)) {
                        good = false;
                        break;
                    }
                }
                if (good) ans++;
            }
        }
        return ans;
    };

    vector<vector<int>> info(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        st.clear();
        for (int j = i + 1; j < n; j++) {
            info[i][j] = info[j][i] = check(i, j);
            st.insert(a[j]);
        }
    }

    vector<ll> f(n + 1, -1);
    function<ll(int)> dfs = [&](int i) -> ll {
        if (i == n - 1) return 1;
        if (f[i] != -1) return f[i];
        ll ans = 0;
        for (int j = i + 1; j < n; j++) {
            ans = (ans + dfs(j) * info[i][j]) % mod;
        }
        return f[i] = ans;
    };
    cout << dfs(0) << "\n";


    return 0;
}

