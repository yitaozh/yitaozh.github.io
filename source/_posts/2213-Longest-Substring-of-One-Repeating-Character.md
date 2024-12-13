---
title: 2213. Longest Substring of One Repeating Character
categories: Leetcode
date: 2024-11-25 22:10:47
tags:
    - Array
    - String
    - Segment Tree
    - Ordered Set
---

[2213. Longest Substring of One Repeating Character](https://leetcode.com/problems/longest-substring-of-one-repeating-character/description/)

## Description

You are given a **0-indexed**  string `s`. You are also given a **0-indexed**  string `queryCharacters` of length `k` and a **0-indexed**  array of integer **indices**  `queryIndices` of length `k`, both of which are used to describe `k` queries.

The `i^th` query updates the character in `s` at index `queryIndices[i]` to the character `queryCharacters[i]`.

Return an array `lengths` of length `k` where `lengths[i]` is the **length**  of the **longest substring**  of `s` consisting of **only one repeating**  character **after**  the `i^th` query is performed.

**Example 1:**

```bash
Input: s = "babacc", queryCharacters = "bcb", queryIndices = [1,3,3]
Output: [3,3,4]
```

Explanation:

- 1^st query updates s = "b**b** bacc". The longest substring consisting of one repeating character is "bbb" with length 3.
- 2^nd query updates s = "bbb**c** cc".
  The longest substring consisting of one repeating character can be "bbb" or "ccc" with length 3.
- 3^rd query updates s = "bbb**b** cc". The longest substring consisting of one repeating character is "bbbb" with length 4.
Thus, we return [3,3,4].

**Example 2:**

```bash
Input: s = "abyzz", queryCharacters = "aa", queryIndices = [2,1]
Output: [2,3]
```

Explanation:

- 1^st query updates s = "ab**a**zz". The longest substring consisting of one repeating character is "zz" with length 2.
- 2^nd query updates s = "a**a**azz". The longest substring consisting of one repeating character is "aaa" with length 3.
Thus, we return [2,3].

**Constraints:**

- `1 <= s.length <= 10^5`
- `s` consists of lowercase English letters.
- `k == queryCharacters.length == queryIndices.length`
- `1 <= k <= 10^5`
- `queryCharacters` consists of lowercase English letters.
- `0 <= queryIndices[i] < s.length`

## Hints/Notes

- 2024/11/13
- segment tree
- [0x3F's solution](https://leetcode.cn/problems/longest-substring-of-one-repeating-character/solutions/1352584/by-endlesscheng-qpbw/)(checked)

## Solution

Language: **C++**

```C++
class Solution {
public:
    // what information do we need to keep?
    // 0. the longest substring length
    // 1. the left character length
    // 2. the right character length
    vector<array<int, 3>> t;

    vector<int> longestRepeating(string s, string queryCharacters,
                                 vector<int>& queryIndices) {
        int n = s.size(), k = queryCharacters.size();
        t.resize(2 << (32 - __builtin_clz(n)));
        build(s, 1, 0, n - 1);
        vector<int> res;
        for (int i = 0; i < k; i++) {
            int idx = queryIndices[i];
            s[idx] = queryCharacters[i];
            update(idx, 1, 0, n - 1, s);
            res.push_back(t[1][0]);
        }
        return res;
    }

    void update(int idx, int o, int l, int r, string& s) {
        auto& t0 = t[o];
        if (l == r) {
            return;
        }
        int m = (l + r) / 2;
        if (idx <= m) {
            update(idx, o * 2, l, m, s);
        } else {
            update(idx, o * 2 + 1, m + 1, r, s);
        }
        maintain(s, o, l, r);
    }

    void build(string& s, int o, int l, int r) {
        auto& t0 = t[o];
        if (l == r) {
            t0[0] = t0[1] = t0[2] = 1;
            return;
        }
        int m = (l + r) / 2;
        build(s, o * 2, l, m);
        build(s, o * 2 + 1, m + 1, r);
        maintain(s, o, l, r);
    }

    void maintain(string& s, int o, int l, int r) {
        // how to get the new values
        auto &t1 = t[o * 2], &t2 = t[o * 2 + 1];
        int m = (l + r) / 2;
        t[o][1] = t1[1];
        if (t1[1] == m - l + 1 && s[m] == s[m + 1]) {
            t[o][1] += t2[1];
        }
        t[o][2] = t2[2];
        if (t2[2] == r - m && s[m] == s[m + 1]) {
            t[o][2] += t1[2];
        }
        // about the new longest substring, it can be the following cases:
        // 1. the longest substring in t1/t2
        // 2. the combined longest string
        int combinedLen = s[m] == s[m + 1] ? t1[2] + t2[1] : 0;
        t[o][0] = max(combinedLen, max(t1[0], t2[0]));
    }
};
```
