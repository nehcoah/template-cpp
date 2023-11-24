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

    double avg = 0;
    for (int i = 0; i < n; i++) avg += a[i];
    avg /= n;

    double D = 0;
    for (int i = 0; i < n; i++) D += (a[i] - avg) * (a[i] - avg);
    D /= n;

    cout << fixed << setprecision(16);
    for (int i = 0; i < n; i++) {
        cout << (a[i] - avg) / sqrt(D) << "\n";
    }

    return 0;
}


