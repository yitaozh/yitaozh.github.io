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
