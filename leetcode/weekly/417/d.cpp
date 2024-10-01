class Solution {
public:
    char kthCharacter(long long k, vector<int>& operations) {
        vector<long long> len{1};
        while (len.back() < k) {
            len.push_back(len.back() * 2);
        }

        auto dfs = [&](auto self, long long p, long long cur) -> pair<char, int> {
            if (p == 1 && cur == 1) return {'a', 0};
            auto [c, id] = self(self, p > cur / 2 ? p - cur / 2 : p, cur / 2);
            if (p > cur / 2 && operations[id] == 1) c = c == 'z' ? 'a' : c + 1;
            return {c, id + 1};
        };

        return dfs(dfs, k, len.back()).first;
    }
};
