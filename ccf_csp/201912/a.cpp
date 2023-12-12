#include "bits/stdc++.h"

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a(4);

    auto check = [&](int x) {
        if (x % 7 == 0) return false;
        while (x) {
            if (x % 10 == 7) return false;
            x /= 10;
        }
        return true;
    };

    for (int i = 1, cnt = 1; cnt <= n; i++) {
        if (!check(i)) a[(i - 1) % 4]++;
        else cnt++;
    }
    for (int i = 0; i < 4; i++) {
        cout << a[i] << "\n";
    }

    return 0;
}

