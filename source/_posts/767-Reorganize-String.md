---
title: 767. Reorganize String
categories: Leetcode
date: 2025-02-12 14:53:14
tags:
    - Hash Table
    - String
    - Greedy
    - Sorting
    - Heap (Priority Queue)
    - Counting
---

[767. Reorganize String](https://leetcode.com/problems/reorganize-string/description/?envType=company&envId=facebook&favoriteSlug=facebook-three-months)

## Description

Given a string `s`, rearrange the characters of `s` so that any two adjacent characters are not the same.

Return any possible rearrangement of `s` or return `""` if not possible.

**Example 1:**

```bash
Input: s = "aab"
Output: "aba"
```

**Example 2:**

```bash
Input: s = "aaab"
Output: ""
```

**Constraints:**

- `1 <= s.length <= 500`
- `s` consists of lowercase English letters.

## Hints/Notes

- 2025/02/05 Q1
- priority queue
- [Leetcode solution](https://leetcode.com/problems/reorganize-string/editorial/?envType=company&envId=facebook&favoriteSlug=facebook-three-months)(checked)

## Solution

Language: **C++**

```C++
class Solution {
public:
    string reorganizeString(string s) {
        map<char, int> m;
        for (char& c : s) {
            m[c]++;
        }
        priority_queue<pair<int,char>> pq;
        for (auto& [k, v] : m) {
            pq.emplace(v, k);
        }
        string res;
        while (!pq.empty()) {
            auto [freq1, c1] = pq.top();
            pq.pop();
            res.push_back(c1);
            freq1--;
            if (pq.empty()) {
                if (freq1 > 0) {
                    return "";
                } else {
                    return res;
                }
            }
            auto [freq2, c2] = pq.top();
            pq.pop();
            res.push_back(c2);
            freq2--;
            if (freq1) pq.emplace(freq1, c1);
            if (freq2) pq.emplace(freq2, c2);
        }
        return res;
    }
};
```
