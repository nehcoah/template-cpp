#include "bits/stdc++.h"

using namespace std;
using ll = long long;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    cout << 1;
    for (int i = 1; i <= n; i++) {
        bool ok = false;
        for (int j = 1; j <= 9; j++) {
            if (n % j == 0 && i % (n / j) == 0) {
                cout << j;
                ok = true;
                break;
            }
        }
        if (!ok) cout << "-";
    }
    cout << endl;

    return 0;
}

