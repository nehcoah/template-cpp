#include "bits/stdc++.h"

using namespace std;
using ll = long long;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<vector<int>> cnt(101, vector<int>(101));
    for (int i = 0; i < n; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        for (int x = a; x < b; x++) {
            for (int y = c; y < d; y++) {
                cnt[x][y]++;
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < 101; i++) {
        for (int j = 0; j < 101; j++) {
            if (cnt[i][j] > 0) ans++;
        }
    }
    cout << ans << endl;

    return 0;
}

