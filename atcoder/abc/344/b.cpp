#include "bits/stdc++.h"

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> a;
    int x;
    while (cin >> x) {
        a.push_back(x);
    }
    reverse(a.begin(), a.end());
    for (int y : a) {
        cout << y << endl;
    }

    return 0;
}
