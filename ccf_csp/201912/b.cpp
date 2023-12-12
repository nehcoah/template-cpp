#include "bits/stdc++.h"

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> x(n), y(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }

    vector<int> ans(5);
    for (int i = 0; i < n; i++) {
        int ok = 0, p = 0;
        for (int j = 0; j < n; j++) {
            if (abs(x[i] - x[j]) == 1 && abs(y[i] - y[j]) == 0 || abs(x[i] - x[j]) == 0 && abs(y[i] - y[j]) == 1) ok++;
            if (abs(x[i] - x[j]) == 1 && abs(y[i] - y[j]) == 1) p++;
        }
        if (ok == 4) ans[p]++;
    }

    for (int i = 0; i < 5; i++) {
        cout << ans[i] << "\n";
    }

    return 0;
}

