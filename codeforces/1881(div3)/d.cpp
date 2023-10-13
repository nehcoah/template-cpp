#include "bits/stdc++.h"

using namespace std;
using ll = long long;

vector<int> minp;
const int N = 1e6 + 1;

auto init = [](){
    minp.assign(N, -1);
    for (int i = 2; i < N; i++) {
        if (minp[i] != -1) continue;
        for (int j = i; j < N; j += i) {
            minp[j] = i;
        }
    }
    return 0;
}();

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    map<int, int> mp;
    for (int x : a) {
        while (x > 1) {
            mp[minp[x]]++;
            x /= minp[x];
        }
    }
    for (auto [k, v] : mp) {
        if (v % n != 0) {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
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

