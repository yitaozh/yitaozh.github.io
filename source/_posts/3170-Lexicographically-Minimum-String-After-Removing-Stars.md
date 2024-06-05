---
title: 3170. Lexicographically Minimum String After Removing Stars
categories: Leetcode
date: 2024-06-05 01:29:00
tags:
    - Hash Table
    - String
    - Stack
    - Greedy
    - Heap (Priority Queue)
---

[3170. Lexicographically Minimum String After Removing Stars](https://leetcode.com/problems/lexicographically-minimum-string-after-removing-stars/description/)

## Description

You are given a string `s`. It may contain any number of `'*'` characters. Your task is to remove all `'*'` characters.

While there is a `'*'`, do the following operation:

- Delete the leftmost `'*'` and the **smallest**  non-`'*'` character to its left. If there are several smallest characters, you can delete any of them.

Return the lexicographically smallest resulting string after removing all `'*'` characters.

**Example 1:**

```bash
Input: s = "aaba*"

Output: "aab"

Explanation:

We should delete one of the `'a'` characters with `'*'`. If we choose `s[3]`, `s` becomes the lexicographically smallest.
```

**Example 2:**

```bash
Input: s = "abc"

Output: "abc"

Explanation:

There is no `'*'` in the string.
```

**Constraints:**

- `1 <= s.length <= 10^5`
- `s` consists only of lowercase English letters and `'*'`.
- The input is generated such that it is possible to delete all `'*'` characters.

## Hints/Notes

- Weekly Contest 400

## Solution

Language: **C++**

```C++
class Solution {
public:
    string clearStars(string s) {
        map<int, vector<int>> m;
        unordered_set<int> toRemove;
        string res;
        for (int i = 0; i < s.size(); i++) {
            char c = s[i];
            if (c != '*') {
                m[c - 'a'].push_back(res.size());
                res.push_back(c);
            } else {
                auto it = m.begin();
                int index = it->second.back();
                toRemove.insert(index);
                it->second.pop_back();
                if (it->second.empty()) {
                    m.erase(it);
                }
            }
        }
        string trueRes;
        for (int i = 0; i < res.size(); i++) {
            if (!toRemove.contains(i)) {
                trueRes.push_back(res[i]);
            }
        }
        return trueRes;
    }
};
```
