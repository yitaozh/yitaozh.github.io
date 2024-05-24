---
title: 526. Beautiful Arrangement
categories: Leetcode
date: 2024-05-24 11:12:12
tags:
    - Array
    - Dynamic Programming
    - Backtracking
    - Bit Manipulation
    - Bitmask
---

[526. Beautiful Arrangement](https://leetcode.com/problems/beautiful-arrangement/description/)

Suppose you have `n` integers labeled `1` through `n`. A permutation of those `n` integers `perm` (**1-indexed** ) is considered a **beautiful arrangement**  if for every `i` (`1 <= i <= n`), **either**  of the following is true:

- `perm[i]` is divisible by `i`.
- `i` is divisible by `perm[i]`.

Given an integer `n`, return the **number**  of the **beautiful arrangements**  that you can construct.

**Example 1:**

```bash
Input: n = 2
Output: 2
<b>Explanation:</b>
The first beautiful arrangement is [1,2]:
    - perm[1] = 1 is divisible by i = 1
    - perm[2] = 2 is divisible by i = 2
The second beautiful arrangement is [2,1]:
    - perm[1] = 2 is divisible by i = 1
    - i = 2 is divisible by perm[2] = 1
```

**Example 2:**

```bash
Input: n = 1
Output: 1
```

**Constraints:**

- `1 <= n <= 15`

## Hints/Notes

- dynamic programming

## Solution

Language: **C++**

```C++
class Solution {
public:
    map<int, int> dp;
    int n_;

    int countArrangement(int n) {
        n_ = n;
        return dfs(0);
    }

    int dfs(int i) {
        if (i == (1 << n_) - 1) {
            return 1;
        }
        if (dp.contains(i)) {
            return dp[i];
        }
        int index = __builtin_popcount(i), ans = 0;
        for (int j = 0; j < n_; j++) {
            if (i & (1 << j)) {
                continue;
            }
            if ((j + 1) % (index + 1) == 0 || (index + 1) % (j + 1) == 0) {
                ans += dfs(i | (1 << j));
            }
        }
        dp[i] = ans;
        return ans;
    }
};
```
