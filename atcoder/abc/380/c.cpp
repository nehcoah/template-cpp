#include "bits/stdc++.h"
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    k -= 1;
    string s;
    cin >> s;

    vector<int> e;
    for (int i = 0; i < n; ) {
        if (s[i] == '0') i += 1;
        else {
            int j = i;
            while (j < n && s[j] == '1') j += 1;
            e.push_back(j - 1);
            i = j;
        }
    }

    for (int l = e[k - 1] + 1, r = e[k]; l < r; l++, r--) {
        swap(s[l], s[r]);
    }
    cout << s << endl;

    return 0;
}
