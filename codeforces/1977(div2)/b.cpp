#include "bits/stdc++.h"

//#pragma GCC optimize("O3,unroll-loops")
//#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

using namespace std;
using ll = long long;

void solve() {
    int x;
    cin >> x;
    vector<int> ans(32);
    for (int i = 0; i < 32; i++) {
        ans[i] = x >> i & 1;
    }
    for (int i = 0; i < 32; i++) {
        if (ans[i] == 0) continue;
        int j = i;
        while (j < 32 && ans[j] == 1) {
            if (i != j) ans[j] = 0;
            j += 1;
        }
        if (j > i + 1) ans[j] = 1, ans[i] = -1;
        i = j - 1;
    }
    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " \n"[i == ans.size() - 1];
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
