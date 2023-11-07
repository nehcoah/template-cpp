#include "bits/stdc++.h"

using namespace std;
using ll = long long;
const int mod = 998244353;
const int inf = 0x3f3f3f3f;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int m;
    cin >> m;
    vector<string> s(3);
    for (int i = 0; i < 3; i++) cin >> s[i];

    int ans = 1e5 + 1;
    for (int i = 0; i < 3 * m; i++) {
        for (int j = 0; j < 3 * m; j++) {
            for (int k = 0; k < 3 * m; k++) {
                if (i != j && i != k && j != k && s[0][i % m] == s[1][j % m] && s[1][j % m] == s[2][k % m])
                    ans = min(ans, max(i, max(j, k)));
            }
        }
    }

    cout << (ans == 1e5 + 1 ? -1 : ans) << endl;

    return 0;
}
