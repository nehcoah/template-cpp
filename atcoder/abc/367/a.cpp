#include "bits/stdc++.h"
using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int a, b, c;
    cin >> a >> b >> c;

    for (int i = b; i != c; i = (i + 1) % 24) {
        if (i == a) {
            cout << "No\n";
            return 0;
        }
    }
    cout << "Yes\n";

    return 0;
}

