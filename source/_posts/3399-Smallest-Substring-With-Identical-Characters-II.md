---
title: 3399. Smallest Substring With Identical Characters II
categories: Leetcode
date: 2025-01-10 01:56:59
tags:
    - String
    - Binary Search
---

[3399. Smallest Substring With Identical Characters II](https://leetcode.com/problems/smallest-substring-with-identical-characters-ii/description/)

## Description

You are given a binary string `s` of length `n` and an integer `numOps`.

You are allowed to perform the following operation on `s` **at most**  `numOps` times:

- Select any index `i` (where `0 <= i < n`) and **flip**  `s[i]`. If `s[i] == '1'`, change `s[i]` to `'0'` and vice versa.

You need to **minimize**  the length of the **longest** substring of `s` such that all the characters in the substring are **identical** .

Return the **minimum**  length after the operations.

**Example 1:**

```bash
Input: s = "000001", numOps = 1

Output: 2
```

Explanation:

By changing `s[2]` to `'1'`, `s` becomes `"001001"`. The longest substrings with identical characters are `s[0..1]` and `s[3..4]`.

**Example 2:**

```bash
Input: s = "0000", numOps = 2

Output: 1
```

Explanation:

By changing `s[0]` and `s[2]` to `'1'`, `s` becomes `"1010"`.

**Example 3:**

```bash
Input: s = "0101", numOps = 0

Output: 1
```

**Constraints:**

- `1 <= n == s.length <= 10^5`
- `s` consists only of `'0'` and `'1'`.
- `0 <= numOps <= n`

## Hints/Notes

- 2025/01/11
- binary search
- [0x3F's solution](https://leetcode.cn/problems/smallest-substring-with-identical-characters-ii/solutions/3027031/er-fen-da-an-tan-xin-gou-zao-pythonjavac-3i4f/)(checked)
- Weekly Contest 429 t4

## Solution

Language: **C++**

```C++
class Solution {
public:
    int minLength(string s, int numOps) {
        int left = 1, right = s.size();
        // the achievable length: [left, right)
        while (left < right) {
            int mid = (left + right) / 2;
            // if check(), it means we can achieve mid size
            // with number of op <= numOps
            if (!check(mid, s, numOps)) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return left;
    }

    bool check(int len, string& s, int numOps) {
        int n = s.size(), res = 0;
        if (len == 1) {
            int cur = 0;
            for (char& c : s) {
                if (cur != c - '0') {
                    res++;
                }
                cur ^= 1;
            }
            return min(res, n - res) <= numOps;
        }
        for (int i = 0; i < n; ) {
            int start = i;
            while (i < n && s[i] == s[start]) {
                i++;
            }
            res += (i - start) / (len + 1);
        }
        return res <= numOps;
    }
};
```
