template<typename Info>
class SparseTable {
    vector<vector<Info>> st;
public:
    SparseTable(const vector<Info> &v) {
        int n = v.size(), l1 = ceil(log2(n)) + 1;
        st.assign(n, vector<Info>(l1, Info()));
        for (int i = 0; i < n; i++) {
            st[i][0] = v[i];
        }
        for (int j = 1; j < l1; j++) {
            int pj = 1 << (j - 1);
            for (int i = 0; i + pj < n; i++) {
                st[i][j] = st[i][j - 1] + st[i + (1 << (j - 1))][j - 1];
            }
        }
    }

    Info query(int l, int r) {
        int lt = r - l + 1;
        int q = floor(log2(lt));
        return st[l][q] + st[r - (1 << q) + 1][q];
    }
};
