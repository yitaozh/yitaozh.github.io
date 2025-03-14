---
title: 247. Strobogrammatic Number II
categories: Leetcode
date: 2025-03-13 23:23:49
tags:
    - Array
    - String
    - Recursion
---

[247. Strobogrammatic Number II](https://leetcode.com/problems/strobogrammatic-number-ii/description/)

## Description

Given an integer `n`, return all the **strobogrammatic numbers**  that are of length `n`. You may return the answer in **any order** .

A **strobogrammatic number**  is a number that looks the same when rotated `180` degrees (looked at upside down).

**Example 1:**

```bash
Input: n = 2
Output: ["11","69","88","96"]
```

**Example 2:**

```bash
Input: n = 1
Output: ["0","1","8"]
```

**Constraints:**

- `1 <= n <= 14`

## Hints/Notes

- 2025/03/03 Q2
- dfs
- [0x3F's solution]

## Solution

Language: **C++**

```C++
class Solution {
public:
    vector<string> res;
    string cur;
    // numbers would be the same after 180: 0, 1, 8
    // numbers would be each other after 180: 6, 9
    vector<char> selfReversable = {'0', '1', '8'};
    vector<string> findStrobogrammatic(int n) {
        cur = string(n, '0');
        dfs(0, n - 1);
        return res;
    }

    void dfs(int start, int end) {
        if (start > end) {
            res.push_back(cur);
            return;
        }
        if (start == end) {
            for (char& c : selfReversable) {
                cur[start] = c;
                res.push_back(cur);
            }
            return;
        }
        for (char& c : selfReversable) {
            if (start == 0 && c == '0') {
                continue;
            }
            cur[start] = c;
            cur[end] = c;
            dfs(start + 1, end - 1);
        }
        cur[start] = '6'; cur[end] = '9'; dfs(start + 1, end - 1);
        cur[start] = '9'; cur[end] = '6'; dfs(start + 1, end - 1);
    }
};
```
