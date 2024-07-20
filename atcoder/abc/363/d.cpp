#include "bits/stdc++.h"
using namespace std;

using ll = long long;

int main() {
    ll n;
    cin >> n;
    if (n == 1) {
        cout << 0 << endl;
        return 0;
    }
    n -= 1;

    ll base = 9;
    int cnt = 1;
    while (true) {
        if (n - base > 0) n -= base, cnt += 1;
        else break;
        if (n - base > 0) n -= base, cnt += 1;
        else break;
        base *= 10;
    }

    string ans = string(cnt, '0');
    if (n == 1) {
        ans[0] = ans.back() = '1';
        cout << ans << endl;
        return 0;
    }
    n -= 1;
    for (int i = (cnt - 1) / 2, j = cnt / 2; i >= 0 && j < cnt; i--, j++) {
        if (i == 0) ans[i] = ans[j] = char('1' + n % 10);
        else ans[i] = ans[j] = char('0' + n % 10);
        n /= 10;
    }
    cout << ans << endl;

    return 0;
}
