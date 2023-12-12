// 90

#include "bits/stdc++.h"

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    auto check = [&](string &s) {
        map<string, int> mp;
        string t;
        stringstream io(s);
        stack<int> stk;
        while (getline(io, t, '+')) {
            int i = 0;
            while (isdigit(t[i])) i++;
            int k = i == 0 ? 1 : stoi(t.substr(0, i));
            t = t.substr(i);
//            cout << k << " " << t << endl;

            for (i = t.size() - 1; i >= 0; ) {
                int j = i;
                while (i >= 0 && isdigit(t[i])) i--;
                int c = i == j ? 1 : stoi(t.substr(i + 1, j - i));
//                cout << c << endl;
                if (t[i] == ')') {
                    stk.push(c);
                    i--;
                    k *= c;
                } else if (t[i] == '(') {
                    k /= stk.top();
                    stk.pop();
                    i--;
                } else {
                    if (islower(t[i])) {
                        mp[t.substr(i - 1, 2)] += k * c;
                        i -= 2;
                    } else {
                        mp[t.substr(i, 1)] += k * c;
                        i -= 1;
                    }
                }
            }
        }
        return mp;
    };

    for (int x = 0; x < n; x++) {
        string s;
        cin >> s;
        auto p = s.find('=');
        string l = s.substr(0, p), r = s.substr(p + 1);
//        cout << l << " " << r << endl;

        auto lm = check(l), rm = check(r);
        if (lm == rm) cout << "Y\n";
        else cout << "N\n";
    }

    return 0;
}

