//
// Created by Nehcoah on 2023/9/11.
//

#include <vector>
#include <iostream>

using namespace std;

struct Trie_lowercase {
    // lowercase characters
private:
    vector<Trie_lowercase*> next;
    bool isEnd;

    Trie_lowercase* search_prefix(string s) {
        Trie_lowercase* cur = this;
        for (char c : s) {
            if (cur->next[c - 'a'] == nullptr) return nullptr;
            cur = cur->next[c - 'a'];
        }
        return cur;
    }

public:
    Trie_lowercase(): next(26), isEnd(false) {}

    void insert(string s) {
        Trie_lowercase* cur = this;
        for (char c : s) {
            if (cur->next[c - 'a'] == nullptr) cur->next[c - 'a'] = new Trie_lowercase();
            cur = cur->next[c - 'a'];
        }
        cur->isEnd = true;
    }

    bool search(string s) {
        auto cur = this->search_prefix(s);
        return cur != nullptr && cur->isEnd;
    }

    bool start_with(string s) {
        return this->search_prefix(s) != nullptr;
    }
};

struct Trie {
    // any characters
private:
    bool is_end;
    unordered_map<char, Trie*> next;

    Trie* search_prefix(string s) {
        Trie* cur = this;
        for (char c : s) {
            if (cur->next.count(c) == 0) return nullptr;
            cur = cur->next[c];
        }
        return cur;
    }

public:
    Trie(): is_end(false) {}

    void insert(string s) {
        Trie* cur = this;
        for (char c : s) {
            if (cur->next.count(c) == 0) cur->next[c] = new Trie();
            cur = cur->next[c];
        }
        cur->is_end = true;
    }

    // has string s?
    bool search(string s) {
        auto cur = this->search_prefix(s);
        return cur != nullptr && cur->is_end;
    }

    // has prefix s?
    bool start_with(string s) {
        return this->search_prefix(s) != nullptr;
    }
};