#include "bits/stdc++.h"

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int k, g, m;
    cin >> k >> g >> m;

    int gc = 0, mc = 0;
    for (int i = 0; i < k; i++) {
        if (gc == g) gc = 0;
        else if (mc == 0) mc = m;
        else {
            if (g - gc < mc) mc -= g - gc, gc = g;
            else gc += mc, mc = 0;
        }
    }
    cout << gc << " " << mc << endl;

    return 0;
}

