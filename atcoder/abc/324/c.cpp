#include "bits/stdc++.h"

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    string s;
    cin >> n >> s;
    vector<string> t(n);
    for (int i = 0; i < n; i++) cin >> t[i];

    auto check = [&](string& cur) {
        if (cur == s) return true;
        if (cur.size() + 1 == s.size()) {
            int diff = 0;
            for (int i = 0; i < cur.size(); i++) {
                if (cur[i] != s[i + diff]) {
                    if (diff == 1) return false;
                    if (cur[i] == s[i + 1]) diff = 1;
                    else return false;
                }
            }
            return true;
        } else if (cur.size() - 1 == s.size()) {
            int diff = 0;
            for (int i = 0; i < s.size(); i++) {
                if (cur[i + diff] != s[i]) {
                    if (diff == 1) return false;
                    if (cur[i + 1] == s[i]) diff = 1;
                    else return false;
                }
            }
            return true;
        } else if (cur.size() == s.size()) {
            int diff = 0;
            for (int i = 0; i < s.size(); i++) {
                if (cur[i] != s[i]) {
                    if (diff == 1) return false;
                    diff = 1;
                }
            }
            return true;
        }
        return false;
    };

    vector<int> ans;
    for (int i = 0; i < n; i++) if (check(t[i])) ans.push_back(i);
    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); i++) cout << ans[i] + 1 << " \n"[i == ans.size() - 1];
    return 0;
}

