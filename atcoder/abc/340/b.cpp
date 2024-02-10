#include "bits/stdc++.h"

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int q;
    cin >> q;
    vector<int> a;
    while (q--) {
        int o, x;
        cin >> o >> x;
        if (o == 1) a.push_back(x);
        else cout << a[a.size() - x] << "\n";
    }

    return 0;
}
