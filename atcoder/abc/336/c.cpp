#include "bits/stdc++.h"

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n;
    cin >> n;
    n--;
    if (n == 0) {
        cout << 0 << endl;
        return 0;
    }
    string ans;
    while (n) {
        ans += '0' + n % 5 * 2;
        n /= 5;
    }
    reverse(ans.begin(), ans.end());
    cout << ans << endl;

    return 0;
}
