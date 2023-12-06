#include "bits/stdc++.h"

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> A, B;
    for (int i = 0; i < n; i++) {
        int x, y;
        char c;
        cin >> x >> y >> c;
        if (c == 'A') A.emplace_back(x, y);
        else B.emplace_back(x, y);
    }

    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        int f = 0;
        bool good = true;
        for (auto t : A) {
            int cur = a + b * t.first + c * t.second;
            if (f == 0) f = cur > 0 ? 1 : -1;
            else {
                if (f == 1 && cur < 0) {
                    cout << "No\n";
                    good = false;
                    break;
                }
                if (f == -1 && cur > 0) {
                    cout << "No\n";
                    good = false;
                    break;
                }
            }
        }
        if (!good) continue;
        for (auto t : B) {
            int cur = a + b * t.first + c * t.second;
            if (f == 1 && cur > 0) {
                cout << "No\n";
                good = false;
                break;
            }
            if (f == -1 && cur < 0) {
                cout << "No\n";
                good = false;
                break;
            }
        }
        if (good) cout << "Yes\n";
    }

    return 0;
}

