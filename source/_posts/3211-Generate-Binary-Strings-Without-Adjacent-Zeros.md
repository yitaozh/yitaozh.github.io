---
title: 3211. Generate Binary Strings Without Adjacent Zeros
categories: Leetcode
date: 2024-07-11 14:40:36
tags:
    - String
    - Bit Manipulation
    - Recursion
---

[3211. Generate Binary Strings Without Adjacent Zeros](https://leetcode.com/problems/generate-binary-strings-without-adjacent-zeros/description/)

## Description

You are given a positive integer `n`.

A binary string `x` is **valid** if all substrings of `x` of length 2 contain **at least** one `"1"`.

Return all **valid**  strings with length `n`, in _any order_.

**Example 1:**

```bash
Input: n = 3

Output: ["010","011","101","110","111"]
```

Explanation:

The valid strings of length 3 are: `"010"`, `"011"`, `"101"`, `"110"`, and `"111"`.

**Example 2:**

```bash
Input: n = 1

Output: ["0","1"]
```

Explanation:

The valid strings of length 1 are: `"0"` and `"1"`.

**Constraints:**

- `1 <= n <= 18`

## Hints/Notes

- Weekly Contest 405

## Solution

Language: **C++**

```C++
class Solution {
public:
    int n_;
    vector<string> res;

    vector<string> validStrings(int n) {
        n_ = n;
        string cur;
        traverse(0, true, cur);
        return res;
    }

    void traverse(int index, int prevOne, string& cur) {
        if (index == n_) {
            res.push_back(cur);
            return;
        }

        if (prevOne) {
            cur += "0";
            traverse(index + 1, false, cur);
            cur.pop_back();
        }

        cur += "1";
        traverse(index + 1, true, cur);
        cur.pop_back();
    }
};
```
