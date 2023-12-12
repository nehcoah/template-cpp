#include "bits/stdc++.h"

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    string s;
    cin >> n >> m >> s;

    int p = 0, l = 0;
    int ans = 0;
    for (char c : s) {
        if (c == '0') ans = max(ans, max(p - m, 0) + l), p = 0, l = 0;
        else if (c == '1') p++;
        else l++;
    }
    ans = max(ans, max(p - m, 0) + l);
    cout << ans << endl;

    return 0;
}

