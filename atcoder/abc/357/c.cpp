#include "bits/stdc++.h"

//#pragma GCC optimize("O3,unroll-loops")
//#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    if (n == 0) {
        cout << "#" << endl;
        return 0;
    }

    vector<string> s{"###", "#.#", "###"};

    for (int i = 2; i <= n; i++) {
        vector<string> t(s.size() * 3, string((int) pow(3, i), '.'));
        auto copy = [&](int x, int y) {
            for (int p = 0; p < s.size(); p++) {
                for (int q = 0; q < s.size(); q++) {
                    t[x + p][y + q] = s[p][q];
                }
            }
        };
        int c = pow(3, i - 1);
        copy(0, 0);
        copy(c, 0);
        copy(2 * c, 0);
        copy(0, c);
        copy(0, 2 * c);
        copy(c, 2 * c);
        copy(2 * c, c);
        copy(2 * c, 2 * c);
        swap(s, t);
    }

    for (int i = 0; i < s.size(); i++) {
        cout << s[i] << endl;
    }

    return 0;
}

