#include "bits/stdc++.h"

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int v1, v2, v3;
    cin >> v1 >> v2 >> v3;

    auto calc_v2 = [&](int a1, int b1, int c1, int a2, int b2, int c2) {
        int a_mn = min(a1 + 7, a2 + 7), b_mn = min(b1 + 7, b2 + 7), c_mn = min(c1 + 7, c2 + 7);
        int a_mx = max(a1, a2), b_mx = max(b1, b2), c_mx = max(c1, c2);
        return max(0, a_mn - a_mx) * max(0, b_mn - b_mx) * max(0, c_mn - c_mx);
    };

    auto calc_v3 = [&](int a1, int b1, int c1, int a2, int b2, int c2, int a3, int b3, int c3) {
        int a_mn = min({a1 + 7, a2 + 7, a3 + 7}), b_mn = min({b1 + 7, b2 + 7, b3 + 7}), c_mn = min({c1 + 7, c2 + 7, c3 + 7});
        int a_mx = max({a1, a2, a3}), b_mx = max({b1, b2, b3}), c_mx = max({c1, c2, c3});
        return max(0, a_mn - a_mx) * max(0, b_mn - b_mx) * max(0, c_mn - c_mx);
    };

    for (int x = 0; x <= 7; x++) {
        for (int y = 0; y <= 7; y++) {
            for (int z = 0; z <= 7; z++) {
                for (int a = -7; a <= 7 + x; a++) {
                    for (int b = -7; b <= 7 + y; b++) {
                        for (int c = -7; c <= 7 + z; c++) {
                            int s3 = calc_v3(0, 0, 0, x, y, z, a, b, c);
                            int s2 = calc_v2(0, 0, 0, x, y, z) + calc_v2(0, 0, 0, a, b, c) + calc_v2(x, y, z, a, b, c);
                            s2 -= 3 * v3;
                            int s1 = 1029 - 2 * v2 - 3 * v3;
                            if (s1 == v1 && s2 == v2 && s3 == v3) {
                                cout << "Yes\n";
                                cout << "0 0 0 " << x << " " << y << " " << z << " " << a << " " << b << " " << c << "\n";
                                return 0;
                            }
                        }
                    }
                }
            }
        }
    }
    cout << "No\n";

    return 0;
}
