#include "bits/stdc++.h"
using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> l, r;
    for (int i = 0; i < n; i++) {
        int a; char c;
        cin >> a >> c;
        if (c == 'L') l.push_back(a);
        else r.push_back(a);
    }

    int ans = 0;
    for (int i = 1; i < l.size(); i++) {
        ans += abs(l[i] - l[i - 1]);
    }
    for (int i = 1; i < r.size(); i++) {
        ans += abs(r[i] - r[i - 1]);
    }
    cout << ans << endl;

    return 0;
}

