#include "bits/stdc++.h"

using namespace std;
using ll = long long;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int q;
    cin >> q;

    multiset<int> s, e;
    for (int i = 0; i < q; i++) {
        char o;
        int l, r;
        cin >> o >> l >> r;
        if (o == '+') {
            s.insert(l);
            e.insert(r);
        } else {
            s.erase(s.find(l));
            e.erase(e.find(r));
        }
        if (s.empty()) cout << "NO" << endl;
        else if (*(prev(s.end())) > *e.begin()) cout << "YES" << endl;
        else cout << "NO" << endl;
    }

    return 0;
}

