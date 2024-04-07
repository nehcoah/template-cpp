#include "bits/stdc++.h"

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    map<int, int> mp;
    for (int i = 0; i < n; i++) {
        int a, c;
        cin >> a >> c;
        if (mp.count(c)) mp[c] = min(mp[c], a);
        else mp[c] = a;
    }
    int ans = 0;
    for (auto [k, v] : mp) {
        ans = max(ans, v);
    }
    cout << ans << endl;

    return 0;
}
