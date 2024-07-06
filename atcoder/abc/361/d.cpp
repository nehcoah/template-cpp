#include "bits/stdc++.h"
using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    string s, t;
    cin >> n >> s >> t;

    if (count(s.begin(), s.end(), 'W') != count(t.begin(), t.end(), 'W')) {
        cout << -1 << endl;
        return 0;
    }

    s += "..";
    auto check = [&](string &x) {
        return t == x.substr(0, n);
    };

    int ans = 0;
    queue<string> q;
    q.push(s);
    set<string> st{s};
    while (!q.empty()) {
        for (int i = q.size(); i; i--) {
            auto x = q.front(); q.pop();
            if (check(x)) {
                cout << ans << endl;
                return 0;
            }
            auto p = find(x.begin(), x.end(), '.') - x.begin();
            for (int j = 0; j < x.size() - 1; j++) {
                if (x[j] != '.' && x[j + 1] != '.') {
                    auto y = x;
                    swap(y[j], y[p]);
                    swap(y[j + 1], y[p + 1]);
                    if (st.count(y) == 0) {
                        st.insert(y);
                        q.push(y);
                    }
                }
            }
        }
        ans += 1;
    }
    cout << -1 << endl;

    return 0;
}
