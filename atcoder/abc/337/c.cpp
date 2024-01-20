#include "bits/stdc++.h"

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, p = -1;
    cin >> n;
    vector<int> a(n), b(n + 1, -1);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] == -1) p = i + 1;
        else b[a[i]] = i + 1;
    }
    for (int x = p; x != -1; x = b[x]) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
