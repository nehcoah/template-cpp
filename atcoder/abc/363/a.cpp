#include "bits/stdc++.h"
using namespace std;

using ll = long long;

int main() {
    int r;
    cin >> r;

    for (int i = 100; i <= 300; i += 100) {
        if (r < i) {
            cout << i - r << endl;
            return 0;
        }
    }

    return 0;
}
