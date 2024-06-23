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
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<int> stk{-1};
    vector<ll> ans(n);
    for (int i = 0; i < n; i++) {
        while (stk.back() != -1 && a[stk.back()] <= a[i]) stk.pop_back();
        ans[i] = (stk.back() == -1 ? 0 : ans[stk.back()] - 1) + 1ll * (i - stk.back()) * a[i] + 1;
        stk.push_back(i);
    }
    for (int i = 0; i < n; i++) {
        cout << ans[i] << " \n"[i == n - 1];
    }

    return 0;
}
