#include "bits/stdc++.h"
using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int a, b;
    cin >> a >> b;
    if (a > b) swap(a, b);
    set<int> st;
    int s = b - a;
    st.insert(a - s);
    st.insert(b + s);
    if (s % 2 == 0) st.insert(b - s / 2);
    cout << st.size() << endl;

    return 0;
}

