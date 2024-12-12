---
title: 3291. Minimum Number of Valid Strings to Form Target I
categories: Leetcode
date: 2024-10-15 16:29:37
tags:
    - Array
    - String
    - Binary Search
    - Dynamic Programming
    - Trie
    - Segment Tree
    - Rolling Hash
    - String Matching
    - Hash Function
---

[3291. Minimum Number of Valid Strings to Form Target I](https://leetcode.com/problems/minimum-number-of-valid-strings-to-form-target-i/description/)

## Description

You are given an array of strings `words` and a string `target`.

A string `x` is called **valid**  if `x` is a prefix of **any**  string in `words`.

Return the **minimum**  number of **valid**  strings that can be concatenated to form `target`. If it is **not**  possible to form `target`, return `-1`.

**Example 1:**

```bash
Input: words = ["abc","aaaaa","bcdef"], target = "aabcdabc"

Output: 3
```

Explanation:

The target string can be formed by concatenating:

- Prefix of length 2 of `words[1]`, i.e. `"aa"`.
- Prefix of length 3 of `words[2]`, i.e. `"bcd"`.
- Prefix of length 3 of `words[0]`, i.e. `"abc"`.

**Example 2:**

```bash
Input: words = ["abababab","ab"], target = "ababaababa"

Output: 2
```

Explanation:

The target string can be formed by concatenating:

- Prefix of length 5 of `words[0]`, i.e. `"ababa"`.
- Prefix of length 5 of `words[0]`, i.e. `"ababa"`.

**Example 3:**

```bash
Input: words = ["abcdef"], target = "xyz"

Output: -1
```

**Constraints:**

- `1 <= words.length <= 100`
- `1 <= words[i].length <= 5 * 10^3`
- The input is generated such that `sum(words[i].length) <= 10^5`.
- `words[i]` consists only of lowercase English letters.
- `1 <= target.length <= 5 * 10^3`
- `target` consists only of lowercase English letters.

## Hints/Notes

- 2024/09/11
- Trie + backtracking
- [0x3F's solution](https://leetcode.cn/problems/minimum-number-of-valid-strings-to-form-target-i/solutions/2917933/ac-zi-dong-ji-you-hua-dppythonjavacgo-by-49jt/)(checked)
- Weekly Contest 415

## Solution

Language: **C++**

```C++
class Solution {
public:
    struct TrieNode {
        vector<TrieNode*> children;
        TrieNode() {
            children = vector<TrieNode*>(26, nullptr);
        }
    };
    TrieNode* root;
    string target_;
    unordered_map<int, int> dp;

    int minValidStrings(vector<string>& words, string target) {
        root = new TrieNode();
        target_ = target;
        // dp.resize(target.size(), INT_MAX);
        for (string word : words) {
            TrieNode* cur = root;
            for (char c : word) {
                if (!cur->children[c - 'a']) {
                    cur->children[c - 'a'] = new TrieNode();
                }
                cur = cur->children[c - 'a'];
            }
        }
        int res = dfs(0);
        return res == INT_MAX ? -1 : res;
    }

    int dfs(int index) {
        if (index == target_.size()) {
            return 0;
        }
        if (dp.contains(index)) {
            return dp[index];
        }
        long res = INT_MAX;
        TrieNode* cur = root;
        int end = index;
        for (end = index; end < target_.size() && cur; end++) {
            cur = cur->children[target_[end] - 'a'];
            if (!cur) {
                break;
            }
        }
        // two cases the end stop:
        //  1. the end reaches the end of target
        //  2. the cur is not valid, so cur is valid at end - 1
        //     and we can only matches [index, end - 2]
        if (end == target_.size() && cur) {
            res = 1;
        } else {
            for (int i = end - 1; i >= index; i--) {
                res = min(res, (long)dfs(i + 1) + 1);
            }
        }
        dp[index] = res;
        return res;
    }
};
```
