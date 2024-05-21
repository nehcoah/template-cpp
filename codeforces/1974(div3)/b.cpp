#include "bits/stdc++.h"

//#pragma GCC optimize("O3,unroll-loops")
//#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

using namespace std;
using ll = long long;

void solve() {
    int n;
    string s;
    cin >> n >> s;
    vector<int> cnt(26);
    for (char c : s) {
        cnt[c - 'a'] = 1;
    }
    string pat;
    for (int i = 0; i < 26; i++) {
        if (cnt[i]) pat += char(i + 'a');
    }
    for (int i = 0; i < pat.size(); i++) {
        cnt[pat[i] - 'a'] = pat[pat.size() - i - 1];
    }
    for (char &c : s) {
        c = char(cnt[c - 'a']);
    }
    cout << s << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
