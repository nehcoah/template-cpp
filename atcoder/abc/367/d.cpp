#include "bits/stdc++.h"
using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i] %= m;
    }
    for (int i = 0; i < n - 2; i++) {
        a.push_back(a[i]);
    }
    ll ans = 0, sum = 0;
    unordered_map<ll, set<int>> mp;
    mp[0].insert(-1);
    for (int i = 0; i < a.size(); i++) {
        sum = (sum + a[i]) % m;
        auto &cur = mp[sum];
        while (!cur.empty() && *cur.begin() < i - n + 1) {
            cur.erase(cur.begin());
        }
        if (i >= n - 2) ans += cur.size();
        mp[sum].insert(i);
    }
    cout << ans << endl;

    return 0;
}

