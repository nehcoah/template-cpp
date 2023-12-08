#include "bits/stdc++.h"

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // 0 -> Upper, 1 -> Lower, 2 -> digit
    int mode = 0;
    vector<int> info;

    int w, s;
    string t;
    cin >> w >> s >> t;
    for (char c : t) {
        if (isdigit(c)) {
            if (mode != 2) info.push_back(28);
            info.push_back(c - '0');
            mode = 2;
        } else if (islower(c)) {
            if (mode != 1) info.push_back(27);
            info.push_back(c - 'a');
            mode = 1;
        } else {
            if (mode != 0) {
                if (mode == 1) info.push_back(28);
                info.push_back(28);
            }
            info.push_back(c - 'A');
            mode = 0;
        }
    }
    if (info.size() % 2 == 1) info.push_back(29);

    vector<int> d(1), g{1, 926};
    int k = s == -1 ? 0 : pow(2, s + 1), cur = 926, mod = 929;
    for (int i = 0; i < info.size(); i += 2) {
        d.push_back(info[i] * 30 + info[i + 1]);
    }
    int append = (int(d.size()) + k) % w;
    if (append > 0) append = w - append;
    for (int i = 0; i < append; i++) {
        d.push_back(900);
    }
    d[0] = d.size();
    
    auto ans = d;
    if (s != -1) {
        for (int i = 0; i < k; i++) d.push_back(0);
        for (int i = 1; i < k; i++) {
            cur = cur * 3 % mod;
            vector<int> c{1, cur}, curg(g.size() + 1);
            for (int x = 0; x < g.size(); x++) {
                for (int y = 0; y < 2; y++) {
                    curg[x + y] = (curg[x + y] + g[x] * c[y] % mod) % mod;
                }
            }
            g.swap(curg);
        }
        for (int i = 0; i <= d.size() - g.size(); i++) {
            int x = d[i]; d[i] = 0;
            for (int j = 1; j < g.size(); j++) {
                d[i + j] = ((d[i + j] - g[j] * x) % mod + mod) % mod;
            }
        }
        for (int i = d.size() - g.size() + 1; i < d.size(); i++) {
            ans.push_back((-d[i] + mod) % mod);
        }
    }

    for (int i = 0; i < ans.size(); i++) cout << ans[i] << "\n";

    return 0;
}
