// https://leetcode.cn/problems/greatest-common-divisor-traversal/description/

int N = 1e5 + 5;
bool init = false;
vector<vector<int>> fac(N);
void get(){
    if (init) return;
    init = true;
    for (int i = 2; i < N; i++){
        if (fac[i].empty()){
            for (int j = i; j < N; j += i) fac[j].push_back(i);
        }
    }
}

class Solution {
public:
    bool canTraverseAllPairs(vector<int>& nums) {
        get();
        int n = nums.size();
        int mx = *max_element(nums.begin(), nums.end());
        vector<int> parent(n + mx + 1);
        iota(parent.begin(), parent.end(), 0);
        function<int(int)> find = [&](int x){
            if (parent[x] != x) parent[x] = find(parent[x]);
            return parent[x];
        };
        function<void(int, int)> merge = [&](int x, int y){
            x = find(x), y = find(y);
            if (x == y) return;
            parent[y] = x;
        };
        for (int i = 0; i < n; i++){
            for (int x : fac[nums[i]]){
                merge(i, x + n);
            }
        }
        unordered_set<int> st;
        for (int i = 0; i < n; i++) st.insert(find(i));
        return st.size() == 1;
    }
};
