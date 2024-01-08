#include "bits/stdc++.h"

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<vector<int>> s(n, vector<int>(n));
    int cnt = 1, l = 0, r = n - 1, t = 0, b = n - 1, c = 0;
    while (cnt < n * n - 1) {
        for (int i = l; i <= r; i++) s[t][i] = cnt++;
        t++;
        for (int i = t; i <= b; i++) s[i][r] = cnt++;
        r--;
        for (int i = r; i >= l; i--) s[b][i] = cnt++;
        b--;
        for (int i = b; i >= t; i--) s[i][l] = cnt++;
        l++;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (s[i][j] == 0) cout << "T ";
            else cout << s[i][j] << " \n"[j == n - 1];
        }
    }

    return 0;
}

