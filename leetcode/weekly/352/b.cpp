// https://leetcode.cn/problems/prime-pairs-with-target-sum/description/

int N = 1e6 + 1;
vector<bool> isPrime;
auto init = [](){
    isPrime.resize(N, true);
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i < N; i++){
        if (isPrime[i]){
            for (int j = i * 2; j < N; j += i) {
                isPrime[j] = false;
            }
        }
    }
    return 0;
}();

class Solution {
public:
    vector<vector<int>> findPrimePairs(int n) {
        vector<vector<int>> ans;
        for (int i = 2; i <= n / 2; i++) if (isPrime[i] && isPrime[n - i]) ans.push_back({i, n - i});
        return ans;
    }
};
