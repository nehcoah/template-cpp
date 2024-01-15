#include "bits/stdc++.h"

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n;
    cin >> n;

    string s = to_string(n);
    int m = s.length();
    ll ans = 0;

    for (int sum = 1; sum < 9 * m + 1; sum++) {
        vector f(m + 1, vector(sum + 1, vector<long long>(sum + 1, -1)));
        function<ll(int, int, int, bool, bool)> dfs = [&](int i, int mod, int t, bool isLimit, bool isNum) -> ll {
            if (t > sum) return 0;
            if (i == m) return isNum && mod == 0 && sum == t;
            if (!isLimit && isNum && f[i][mod][t] != -1) return f[i][mod][t];
            ll ans = 0;
            if (!isNum) ans = dfs(i + 1, mod, t, false, false);

            int up = isLimit ? s[i] - '0' : 9;
            for (int d = 1 - isNum; d <= up; d++) {
                ans += dfs(i + 1, (mod * 10 + d) % sum, t + d, isLimit && d == up, true);
            }
            if (!isLimit && isNum) f[i][mod][t] = ans;
            return ans;
        };
        ans += dfs(0, 0, 0, true, false);
    }

    cout << ans << endl;

    return 0;
}
