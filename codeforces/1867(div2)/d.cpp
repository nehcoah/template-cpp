#include "bits/stdc++.h"

#define endl '\n'
using namespace std;
using ll = long long;
const int mod = 998244353;
const int inf = 0x3f3f3f3f;

void solve() {
    int n, k; cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i]--;
    }
    if (k == 1) {
        for (int i = 0; i < n; i++) if (a[i] != i) {
            cout << "NO" << endl;
            return;
        }
        cout << "YES" << endl;
        return;
    }
    vector<int> time(n, -1);
    vector<pair<int, int>> info;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (time[i] == -1) {
            int start = cnt;
            for (int cur = i; ; cur = a[cur], cnt++) {
                if (time[cur] != -1) {
                    if (time[cur] >= start) {
                        if (cnt - time[cur] != k) {
		             cout << "NO" << endl;
		             return;
	                 }
                    }
                    break;
                }
                time[cur] = cnt;
            }
        }
    }
    cout << "YES" << endl;
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
