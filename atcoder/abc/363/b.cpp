#include "bits/stdc++.h"
using namespace std;

using ll = long long;

int main() {
    int n, t, p;
    cin >> n >> t >> p;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end(), greater());
    cout << max(0, t - a[p - 1]) << endl;

    return 0;
}
