#include "bits/stdc++.h"

//#pragma GCC optimize("O3,unroll-loops")
//#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    string s;
    set<string> s1, s2, ans;

    auto check = [&](int t) {
        cin >> s;
        for (char &c : s) {
            if (isupper(c)) c = tolower(c);
        }
        if (t) s1.insert(s);
        else s2.insert(s);
    };

    for (int i = 0; i < n; i++) {
        check(1);
    }
    for (int i = 0; i < m; i++) {
        check(0);
    }

    set_union(s1.begin(), s1.end(), s2.begin(), s2.end(), inserter(ans, ans.begin()));
    int u = ans.size();
    ans.clear();
    set_intersection(s1.begin(), s1.end(), s2.begin(), s2.end(), inserter(ans, ans.begin()));
    int i = ans.size();
    cout << i << endl;
    cout << u << endl;

    return 0;
}
