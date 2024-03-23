#include "bits/stdc++.h"

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n;
    cin >> n;
    string s, t;
    cin >> s >> t;

    vector idx(26, vector<int>());
    for (int i = 0; i < s.size(); i++) {
        idx[s[i] - 'a'].push_back(i);
    }
    auto check = [&](ll k) {
        if (k == 0) return true;
        ll cnt = 1, pos = 0;
        for (char c : t) {
            ll sz = idx[c - 'a'].size();
            if (sz == 0) return false;
            cnt += k / sz - (k % sz == 0);
            ll left = k % sz;
            if (left == 0) left = sz;
            int x = lower_bound(idx[c - 'a'].begin(), idx[c - 'a'].end(), pos) - idx[c - 'a'].begin();
            if (x == sz) x = 0, cnt += 1;
            if (x + left - 1 >= sz) {
                pos = idx[c - 'a'][(x + left - 1 + sz) % sz] + 1;
                cnt += 1;
            } else {
                pos = idx[c - 'a'][x + left - 1] + 1;
            }
            if (cnt > n) return false;
        }
        return cnt <= n;
    };

    ll l = 0, r = 1e18;
    while (l < r) {
        ll mid = (l + r + 1) >> 1;
        if (check(mid)) l = mid;
        else r = mid - 1;
    }
    cout << l << endl;

    return 0;
}
