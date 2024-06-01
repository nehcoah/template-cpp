#include "bits/stdc++.h"

//#pragma GCC optimize("O3,unroll-loops")
//#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    auto check = [&](int x, int y) {
        int f = 0;
        if (x < y) swap(x, y), f = 1;
        vector<int> t{x};
        if (x % y == 0 && __builtin_popcount(x / y) == 1) {
            while (x > y) t.push_back(x / 2), x /= 2;
        } else {
            vector<int> T{y};
            while (x != y) {
                if (x > y) t.push_back(x / 2), x /= 2;
                else T.push_back(y / 2), y /= 2;
            }
            T.pop_back();
            reverse(T.begin(), T.end());
            t.insert(t.end(), T.begin(), T.end());
        }
        if (f) reverse(t.begin(), t.end());
        return t;
    };

    auto ans = a;
    for (int i = 0; i < n; ) {
        int j = i + 1;
        while (j < n && a[j] == -1) j += 1;
        if (j == n) {
            if (a[i] == -1) {
                ans[i] = 2;
            }
            for (int k = i + 1, c = 0; k < j; k++, c++) {
                if (c & 1) ans[k] = ans[k - 1] / 2;
                else ans[k] = ans[k - 1] * 2;
            }
        } else {
            if (a[i] == -1) {
                for (int k = j - 1, c = 0; k >= i; k--, c++) {
                    if (c & 1) ans[k] = ans[k + 1] / 2;
                    else ans[k] = ans[k + 1] * 2;
                }
            } else {
                auto t = check(a[i], a[j]);
                if (j - i + 1 >= t.size() && (j - i + 1 - t.size()) % 2 == 0) {
                    for (int k = i + 1, c = 0; c < (j - i + 1 - t.size()); c++, k++) {
                        if (c & 1) ans[k] = ans[k - 1] / 2;
                        else ans[k] = ans[k - 1] * 2;
                    }
                    for (int k = j - 1, c = t.size() - 2; c > 0; c--, k--) {
                        ans[k] = t[c];
                    }
                } else {
                    cout << -1 << endl;
                    return;
                }
            }
        }
        i = j;
    }
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " \n"[i == ans.size() -1 ];
    }
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

