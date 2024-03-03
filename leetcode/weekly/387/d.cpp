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
    vector<int> resultArray(vector<int>& nums) {
        int n = nums.size();
        auto idx = nums;
        sort(idx.begin(), idx.end());
        idx.erase(unique(idx.begin(), idx.end()), idx.end());
        
        Fenwick<int> t1(n + 5), t2(n + 5);
        int x = lower_bound(idx.begin(), idx.end(), nums[0]) - idx.begin();
        t1.add(x, 1);
        int y = lower_bound(idx.begin(), idx.end(), nums[1]) - idx.begin();
        t2.add(y, 1);
        
        vector<int> arr1{nums[0]}, arr2{nums[1]};
        for (int i = 2; i < n; i++) {
            x = lower_bound(idx.begin(), idx.end(), nums[i]) - idx.begin();
            int c1 = t1.query_interval(x + 1, n + 4);
            int c2 = t2.query_interval(x + 1, n + 4);
            if (c1 > c2) {
                arr1.push_back(nums[i]);
                t1.add(x, 1);
            } else if (c1 < c2) {
                arr2.push_back(nums[i]);
                t2.add(x, 1);
            } else {
                if (arr1.size() <= arr2.size()) {
                    arr1.push_back(nums[i]);
                    t1.add(x, 1);
                } else {
                    arr2.push_back(nums[i]);
                    t2.add(x, 1);
                }
            }
        }
        arr1.insert(arr1.end(), arr2.begin(), arr2.end());
        return arr1;
    }
};
