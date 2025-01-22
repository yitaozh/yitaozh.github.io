---
title: 791. Custom Sort String
categories: Leetcode
date: 2025-01-22 00:36:26
tags:
    - Hash Table
    - String
    - Sorting
---

[791. Custom Sort String](https://leetcode.com/problems/custom-sort-string/description/?envType=company&envId=facebook&favoriteSlug=facebook-three-months)

## Description

You are given two strings `order` and `s`. All the characters of `order` are **unique**  and were sorted in some custom order previously.

Permute the characters of `s` so that they match the order that `order` was sorted. More specifically, if a character `x` occurs before a character `y` in `order`, then `x` should occur before `y` in the permuted string.

Return any permutation of `s` that satisfies this property.

**Example 1:**

```bash
Input: order = "cba", s = "abcd"

Output: "cbad"
```

Explanation: `"a"`, `"b"`, `"c"` appear in order, so the order of `"a"`, `"b"`, `"c"` should be `"c"`, `"b"`, and `"a"`.

Since `"d"` does not appear in `order`, it can be at any position in the returned string. `"dcba"`, `"cdba"`, `"cbda"` are also valid outputs.

**Example 2:**

```bash
Input: order = "bcafg", s = "abcd"

Output: "bcad"
```

Explanation: The characters `"b"`, `"c"`, and `"a"` from `order` dictate the order for the characters in `s`. The character `"d"` in `s` does not appear in `order`, so its position is flexible.

Following the order of appearance in `order`, `"b"`, `"c"`, and `"a"` from `s` should be arranged as `"b"`, `"c"`, `"a"`. `"d"` can be placed at any position since it's not in order. The output `"bcad"` correctly follows this rule. Other arrangements like `"dbca"` or `"bcda"` would also be valid, as long as `"b"`, `"c"`, `"a"` maintain their order.

**Constraints:**

- `1 <= order.length <= 26`
- `1 <= s.length <= 200`
- `order` and `s` consist of lowercase English letters.
- All the characters of `order` are **unique** .

## Hints/Notes

- 2025/01/21
- cmp or count sorting
- [Leetcode solution](https://leetcode.com/problems/custom-sort-string/editorial/?envType=company&envId=facebook&favoriteSlug=facebook-three-months)

## Solution

Language: **C++**

```C++
class Solution {
public:
    string customSortString(string order, string s) {
        unordered_map<char, int> m;
        for (int i = 0; i < order.size(); i++) {
            m[order[i]] = i;
        }
        auto cmp = [&](const char& l, const char& r) {
            return m[l] < m[r];
        };
        sort(s.begin(), s.end(), cmp);
        return s;
    }
};
```
