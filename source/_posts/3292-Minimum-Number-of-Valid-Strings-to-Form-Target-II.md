---
title: 3292. Minimum Number of Valid Strings to Form Target II
categories: Leetcode
date: 2024-10-15 16:31:14
tags:
    - Array
    - String
    - Binary Search
    - Dynamic Programming
    - Segment Tree
    - Rolling Hash
    - String Matching
    - Hash Function
---

[3292. Minimum Number of Valid Strings to Form Target II](https://leetcode.com/problems/minimum-number-of-valid-strings-to-form-target-ii/description/)

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
- `1 <= words[i].length <= 5 * 10^4`
- The input is generated such that `sum(words[i].length) <= 10^5`.
- `words[i]` consists only of lowercase English letters.
- `1 <= target.length <= 5 * 10^4`
- `target` consists only of lowercase English letters.

## Hints/Notes

- the `sum(words[i].length) <= 1e5` indicates that we can use prefix match
- polynomial hashing function, implement a class for it
- Weekly Contest 415

## Solution

Language: **C++**

```C++
class Solution {
public:
    unordered_map<int, unordered_set<long long>> m;

    int minValidStrings(vector<string>& words, string target) {
        int maxLen = 0, MOD = 1e9 + 7, base = 9'999'991;
        for (string word : words) {
            maxLen = max(maxLen, (int)word.size());
        }
        // hash(s) = s[0] * base^(n-1) + s[1] * base^(n-2) + ... + s[n-2] * base + s[n-1]
        for (string word : words) {
            long long cur = 0;
            for (int i = 0; i < min(word.size(), target.size()); i++) {
                cur = (cur * base + word[i]) % MOD;
                m[i + 1].insert(cur);
            }
        }
        int n = target.size();
        vector<long long> preHash(n + 1, 0);
        // why do we need prePow, cause when calculating the hash between
        // target[l, r], we can just use preHash[r + 1] - preHash[l] * prePow(r - l)
        vector<long long> prePow(n + 1, 1);
        for (int i = 0; i < target.size(); i++) {
            preHash[i + 1] = (preHash[i] * base + target[i]) % MOD;
            prePow[i + 1] = (prePow[i] * base) % MOD;
        }
        vector<int> right_most(n);
        for (int i = 0; i < target.size(); i++) {
            int l = i, r = target.size();
            // the meaning of binary search:
            // we try to find the right most index between
            // i and target.size() - 1 that the prefix exists in hashmap
            while (l < r) {
                int mid = (r - l) / 2 + l;
                int h = (((preHash[mid + 1] - preHash[i] * prePow[mid + 1 - i]) % MOD) + MOD) % MOD;
                if (m[mid - i + 1].contains(h)) {
                    l = mid + 1;
                } else {
                    r = mid;
                }
            }
            right_most[i] = l;
        }
        int cur_r = 0, next_r = 0, res = 0;
        for (int i = 0; i < target.size(); i++) {
            next_r = max(next_r, right_most[i]);
            if (i == cur_r) {
                if (i == next_r) {
                    return -1;
                }
                cur_r = next_r;
                res++;
            }
        }
        return res ? res : -1;
    }
};
```
