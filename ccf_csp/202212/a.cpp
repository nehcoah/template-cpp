#include "bits/stdc++.h"

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    double i;
    cin >> n >> i;

    double sum = 0;
    vector<int> c(n + 1);
    for (int j = 0; j < n + 1; j++) cin >> c[j];
    for (int j = n; j >= 0; j--) {
        sum /= (1 + i);
        sum += c[j];
    }
    cout << fixed << setprecision(8) << sum << endl;

    return 0;
}


