#include "bits/stdc++.h"

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    int mx = accumulate(a.begin(), a.end(), 0);
    a.erase(unique(a.begin(), a.end()), a.end());
    int mn = accumulate(a.begin(), a.end(), 0);
    cout << mx << endl;
    cout << mn << endl;

    return 0;
}


