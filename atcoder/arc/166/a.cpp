#include "bits/stdc++.h"

using namespace std;
using ll = long long;

void solve() {
    int n;
    string x, y;
    cin >> n >> x >> y;

    for (int i = 0, pre = -1; i <= n; i++) {
        if (i == n || y[i] == 'C') {
            if (i < n && y[i] == 'C') {
                if (x[i] != 'C') {
                    cout << "No" << endl;
                    return;
                }
            }
            int cnt[3] {};
            for (int j = pre + 1; j < i; j++) {
                cnt[x[j] - 'A']++;
                cnt[y[j] - 'A']--;
            }
            if (cnt[0] > 0 || cnt[1] > 0) {
                cout << "No" << endl;
                return;
            }
            for (int j = pre + 1; j < i; j++) {
                if (x[j] == 'C') {
                    if (cnt[0] < 0) x[j] = 'A', cnt[0]++;
                    else x[j] = 'B';
                }
            }
            int cur = 0;
            for (int j = pre + 1; j < i; j++) {
                cur += x[j] == 'A';
                cur -= y[j] == 'A';
                if (cur < 0) {
                    cout << "No" << endl;
                    return;
                }
            }
            pre = i;
        }
    }
    cout << "Yes" << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}

