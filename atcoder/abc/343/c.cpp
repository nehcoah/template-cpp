#include "bits/stdc++.h"

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n;
    cin >> n;

    auto check = [&](ll x) {
        string s = to_string(x);
        for (int i = 0, j = s.size() - 1; i < j; i++, j--) {
            if (s[i] != s[j]) return false;
        }
        return true;
    };

    ll ans = 0;
    for (ll i = 1; i * i * i <= n; i++) {
        if (check(i * i * i)) ans = max(ans, i * i * i);
    }
    cout << ans << endl;

    return 0;
}
