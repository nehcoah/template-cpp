template<typename Info>
class SparseTable {
    int n;
    vector<vector<Info>> st;
public:
    SparseTable(const vector<Info> &v) {
        n = v.size();
        if (n == 0) return;
        int maxLog = 32 - __builtin_clz(n);
        st.resize(maxLog);
        st[0] = v;
        for (int j = 1; j < maxLog; j++) {
            st[j].resize(n - (1 << j) + 1);
            for (int i = 0; i <= n - (1 << j); i++) {
                st[j][i] = st[j - 1][i] + st[j - 1][i + (1 << (j - 1))];
            }
        }
    }

    Info query(int l, int r) {
        assert(0 <= l && l <= r && r <= n - 1);
        int lg = 31 - __builtin_clz(r - l + 1);
        return st[lg][l] + st[lg][r - (1 << lg) + 1];
    }
};
