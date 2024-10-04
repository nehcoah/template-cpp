#include "bits/stdc++.h"
using namespace std;

using ll = long long;
using ull = unsigned long long;
using u32 = unsigned;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> h(n);
    for (int i = 0; i < n; i++) {
        cin >> h[i];
    }
    vector<int> stk, ans(n);
    for (int i = n - 1; i >= 0; i--) {
        ans[i] = stk.size();
        while (!stk.empty() && stk.back() < h[i]) {
            stk.pop_back();
        }
        stk.push_back(h[i]);
    }
    for (int i = 0; i < n; i++) {
        cout << ans[i] << " \n"[i == n - 1];
    }

    return 0;
}

