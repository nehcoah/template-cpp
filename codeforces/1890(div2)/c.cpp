#include "bits/stdc++.h"

using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    if (n & 1) {
        cout << -1 << endl;
        return;
    }
    vector<int> idx;
    int z = 0, o = 0, pre = 0;
    for (int i = 0, j = n - 1; ; ) {
        if (idx.size() > 300) {
            cout << -1 << endl;
            return;
        }
        if (i >= j) {
            if (z == 0 && o == 0) break;
            else {
                cout << -1 << endl;
                return;
            }
        }
        char l = o > 0 ? '1' : s[i], r = z > 0 ? '0' : s[j];
        if (l == r) {
            if (l == '1') {
                j--;
                idx.push_back(i + pre * 2 - o);
                o++;
                pre++;
            } else {
                i++;
                idx.push_back(j + 1 + pre * 2 + z);
                z++;
            }
        } else {
            if (l == '0') {
                i++; j--;
            } else {
                if (o > 0) o--;
                else i++;
                if (z > 0) z--;
                else j--;
            }
        }
    }

    cout << idx.size() << endl;
    for (int i = 0; i < idx.size(); i++) cout << idx[i] << " ";
    cout << endl;
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

