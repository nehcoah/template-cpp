#include "bits/stdc++.h"

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;
    array<ll, 26> cnt{};
    for (char c : s) {
        cnt[c - 'a'] += 1;
    }
    ll ans = 0, sum = 0, mx = 0;
    for (int i = 0; i < 26; i++) {
        if (cnt[i] == 0) continue;
        ans += sum * cnt[i];
        sum += cnt[i];
        mx = max(mx, cnt[i]);
    }
    cout << ans + (mx > 1 ? 1 : 0) << endl;

    return 0;
}
