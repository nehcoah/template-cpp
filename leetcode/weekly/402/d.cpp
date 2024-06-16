template<typename T>
struct Fenwick {
    int n;
    vector<T> tree;

    Fenwick(int n = 0) {
        init(n);
    }

    void init(int sz) {
        this->n = sz + 1;
        tree.assign(sz + 2, T());
    }

    void clear() {
        tree.assign(n + 2, T());
    }

    void add(int pos, T val) {
        pos++;
        for (; pos < tree.size(); pos += pos & -pos) tree[pos] += val;
    }

    T query(int pos) {
        pos++;
        auto ans = T();
        for (; pos; pos -= pos & -pos) ans += tree[pos];
        return ans;
    }

    T query_interval(int l, int r) {
        assert(l <= r);
        return query(r) - query(l - 1);
    }

};

class Solution {
public:
    vector<int> countOfPeaks(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        Fenwick<int> t(n + 5);
        vector<int> ans;
        for (int i = 1; i < n - 1; i++) {
            if (nums[i] > nums[i - 1] && nums[i] > nums[i + 1]) {
                t.add(i, 1);
            }
        }
        
        auto check = [&](int p) {
            if (p <= 0 || p >= n - 1) return false;
            return nums[p] > nums[p - 1] && nums[p] > nums[p + 1];
        };
        
        for (auto &q : queries) {
            if (q[0] == 1) {
                int l = q[1] + 1, r = q[2] - 1;
                if (l <= r) ans.push_back(t.query_interval(l, r));
                else ans.push_back(0);
            } else {
                int id = q[1], v = q[2];
                if (check(id - 1)) {
                    if (nums[id - 1] <= v) t.add(id - 1, -1);
                } else {
                    if (id - 1 > 0 && nums[id - 1] > nums[id - 2] && nums[id - 1] > v) t.add(id - 1, 1);
                }
                if (check(id)) {
                    if (v <= nums[id - 1] || v <= nums[id + 1]) t.add(id, -1);
                } else {
                    if (id > 0 && id < n - 1 && v > nums[id - 1] && v > nums[id + 1]) t.add(id, 1);
                }
                if (check(id + 1)) {
                    if (nums[id + 1] <= v) t.add(id + 1, -1);
                } else {
                    if (id + 1 < n - 1 && nums[id + 1] > nums[id + 2] && nums[id + 1] > v) t.add(id + 1, 1);
                }
                nums[id] = v;
            }
        }
        return ans;
    }
};
