---
title: 3213. Construct String with Minimum Cost
categories: Leetcode
date: 2024-07-11 15:30:37
tags:
    - Array
    - String
    - Dynamic Programming
    - Suffix Array
---

[3213. Construct String with Minimum Cost](https://leetcode.com/problems/construct-string-with-minimum-cost/description/)

## Description

You are given a string `target`, an array of strings `words`, and an integer array `costs`, both arrays of the same length.

Imagine an empty string `s`.

You can perform the following operation any number of times (including **zero** ):

- Choose an index `i` in the range `[0, words.length - 1]`.
- Append `words[i]` to `s`.
- The cost of operation is `costs[i]`.

Return the **minimum**  cost to make `s` equal to `target`. If it's not possible, return `-1`.

**Example 1:**

```bash
Input: target = "abcdef", words = ["abdef","abc","d","def","ef"], costs = [100,1,1,10,5]

Output: 7
```

Explanation:

The minimum cost can be achieved by performing the following operations:

- Select index 1 and append `"abc"` to `s` at a cost of 1, resulting in `s = "abc"`.
- Select index 2 and append `"d"` to `s` at a cost of 1, resulting in `s = "abcd"`.
- Select index 4 and append `"ef"` to `s` at a cost of 5, resulting in `s = "abcdef"`.

**Example 2:**

```bash
Input: target = "aaaa", words = ["z","zz","zzz"], costs = [1,10,100]

Output: -1
```

Explanation:

It is impossible to make `s` equal to `target`, so we return -1.

**Constraints:**

- `1 <= target.length <= 5 * 10^4`
- `1 <= words.length == costs.length <= 5 * 10^4`
- `1 <= words[i].length <= target.length`
- The total sum of `words[i].length` is less than or equal to `5 * 10^4`.
- `target` and `words[i]` consist only of lowercase English letters.
- `1 <= costs[i] <= 10^4`

## Hints/Notes

- Trie
- Weekly Contest 405

## Solution

Language: **C++**

```C++
class Solution {
public:
    struct Trie {
        int val;
        Trie* children[26];

        Trie(int val) : val(val), children() {}
    };

    Trie* root;
    vector<int> dp;
    string target_;

    int minimumCost(string target, vector<string>& words, vector<int>& costs) {
        root = new Trie(-1);
        target_ = target;
        int n = words.size();
        int size = target.size();
        dp.resize(size, -1);
        for (int i = 0; i < n; i++) {
            string& word = words[i];
            Trie* cur = root;
            for (char& c : word) {
                int idx = c - 'a';
                if (cur->children[idx] == nullptr) {
                    cur->children[idx] = new Trie(INT_MAX);
                }
                cur = cur->children[idx];
            }
            cur->val = min(costs[i], cur->val);
        }
        int res = traverse(0);
        return res == INT_MAX ? -1 : res;
    }

    long traverse(int index) {
        if (index == target_.size()) {
            return 0;
        }
        if (dp[index] != -1) {
            return dp[index];
        }
        long res = INT_MAX;
        Trie* cur = root;
        for (int i = index; i < target_.size(); i++) {
            char& c = target_[i];
            int idx = c - 'a';
            if (cur->children[idx] == nullptr) {
                break;
            }
            if (cur->children[idx]->val != INT_MAX) {
                res = min(res, cur->children[idx]->val + traverse(i + 1));
            }
            cur = cur->children[idx];
        }
        dp[index] = res;
        return res;
    }
};
```

Another approach: string hash

```C++
class Solution {
public:
    struct HashObj {
        const int MOD = 1'070'777'777;
        int n;
        vector<int> P, H;
        template<typename Container> HashObj(Container &s, const int BASE) {
            n = s.size();
            P.resize(n + 1); H.resize(n + 1);
            P[0] = 1; H[0] = 0;
            for (int i = 1; i <= n; i++) {
                P[i] = (long)P[i - 1] * BASE % MOD;
            }
            // hash(s) = s[0] * base^(n-1) + s[1] * base^(n-2) + ... + s[n-2] * base + s[n-1]
            for (int i = 1; i <= n; i++) {
                H[i] = ((long)H[i - 1] * BASE + s[i - 1]) % MOD;
            }
        }

        int query(int l, int r) {
            if (l > r) return 0;
            return (H[r + 1] - (long)H[l] * P[r - l + 1] % MOD + MOD) % MOD;
        }
    };

    int max_size = 0;
    vector<int> dp;
    HashObj* t;
    map<int, unordered_map<int, int>> m;

    int minimumCost(string target, vector<string>& words, vector<int>& costs) {
        mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
        const int BASE = uniform_int_distribution<>(8e8, 9e8)(rng);
        t = new HashObj(target, BASE);
        dp.resize(target.size(), INT_MAX / 2);
        for (int i = 0; i < words.size(); i++) {
            string word = words[i];
            HashObj obj(word, BASE);
            int n = word.size();
            int h = obj.H[n];
            if (m[n].contains(h)) {
                m[n][h] = min(m[n][h], costs[i]);
            } else {
                m[n][h] = costs[i];
            }
        }
        int res = dfs(0);
        delete t;
        return res == INT_MAX / 2 ? -1 : res;
    }

    int dfs(int index) {
        if (index == t->n) {
            return 0;
        }
        if (dp[index] != INT_MAX / 2) {
            return dp[index];
        }
        int res = INT_MAX / 2;
        for (auto& [len, mc] : m) {
            if (len + index > t->n) {
                break;
            }
            int h = t->query(index, index + len - 1);
            if (mc.contains(h)) {
                res = min(res, mc[h] + dfs(index + len));
            }
        }
        dp[index] = res;
        return res;
    }
};
```
