#include "bits/stdc++.h"
using namespace std;

using ll = long long;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    auto id = a;
    sort(a.begin(), a.end());
    cout << find(id.begin(), id.end(), a[n - 2]) - id.begin() + 1 << endl;

    return 0;
}
