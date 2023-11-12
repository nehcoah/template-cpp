using ll = long long;
struct Node {
public:
    array<Node*, 2> next{};
    int cnt = 0;
};

struct BitTrie {
    int mx_base;
    Node *root;

public:
    BitTrie(int base = 31) {
        mx_base = base;
        root = new Node();
    }

    void insert(int x) {
        Node *cur = root;
        for (int i = mx_base; i >= 0; i--) {
            int b = (x >> i) & 1;
            if (cur->next[b] == nullptr) cur->next[b] = new Node();
            cur = cur->next[b];
            cur->cnt++;
        }
    }

    void remove(int x) {
        Node *cur = root;
        for (int i = mx_base; i >= 0; i--) {
            cur = cur->next[(x >> i) & 1];
            cur->cnt--;
        }
    }

    ll max_xor(int x) {
        Node *cur = root;
        ll ans = 0;
        for (int i = mx_base; i >= 0; i--) {
            int b = (x >> i) & 1;
            if (cur->next[b ^ 1] && cur->next[b ^ 1]->cnt) {
                ans |= 1LL << i;
                b ^= 1;
            }
            cur = cur->next[b];
        }
        return ans;
    }
};

class Solution {
public:
    int maximumStrongPairXor(vector<int>& nums) {
        int n = nums.size(), ans = 0;
        BitTrie t(20);
        ranges::sort(nums);
        for (int i = 0, j = 0; i < n; i++) {
            t.insert(nums[i]);
            while (nums[j] * 2 < nums[i]) t.remove(nums[j]), j++;
            ans = max(ans, (int)t.max_xor(nums[i]));
        }
        return ans;
    }
};
