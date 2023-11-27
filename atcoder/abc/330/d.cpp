#include "bits/stdc++.h"

using namespace std;
using ll = long long;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<string> s(n);
    for (int i = 0; i < n; i++) cin >> s[i];

    vector<ll> row(n), col(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            row[i] += s[i][j] == 'o';
            col[j] += s[i][j] == 'o';
        }
    }
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (s[i][j] == 'o') {
                ans += (row[i] - 1) * (col[j] - 1);
            }
        }
    }
    cout << ans << endl;

    return 0;
}


