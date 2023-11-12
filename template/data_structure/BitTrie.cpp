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

    long long max_xor(int x) {
        Node *cur = root;
        long long ans = 0;
        for (int i = mx_base; i >= 0; i--) {
            int b = (x >> i) & 1;
            if (cur->next[b ^ 1] && cur->next[b ^ 1]->cnt) {
                ans |= 1LL << i;
                cur = cur->next[b ^ 1];
            } else {
                cur = cur->next[b];
            }
        }
        return ans;
    }

    long long min_xor(int x) {
        Node *cur = root;
        long long ans = 0;
        for (int i = mx_base; i >= 0; i--) {
            int b = (x >> i) & 1;
            if (cur->next[b] && cur->next[b]->cnt) {
                cur = cur->next[b];
            } else {
                ans |= 1LL << i;
                cur = cur->next[b ^ 1];
            }
        }
        return ans;
    }
};
