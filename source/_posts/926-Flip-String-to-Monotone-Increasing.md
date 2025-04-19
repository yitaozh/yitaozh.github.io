---
title: 926. Flip String to Monotone Increasing
categories: Leetcode
date: 2025-04-19 16:16:22
tags:
    - String
    - Dynamic Programming
---

[926. Flip String to Monotone Increasing](https://leetcode.com/problems/flip-string-to-monotone-increasing/description/?envType=company&envId=snapchat&favoriteSlug=snapchat-more-than-six-months)

## Description

A binary string is monotone increasing if it consists of some number of `0`'s (possibly none), followed by some number of `1`'s (also possibly none).

You are given a binary string `s`. You can flip `s[i]` changing it from `0` to `1` or from `1` to `0`.

Return the minimum number of flips to make `s` monotone increasing.

**Example 1:**

```bash
Input: s = "00110"
Output: 1
Explanation: We flip the last digit to get 00111.
```

**Example 2:**

```bash
Input: s = "010110"
Output: 2
Explanation: We flip to get 011111, or alternatively 000111.
```

**Example 3:**

```bash
Input: s = "00011000"
Output: 2
Explanation: We flip to get 00000000.
```

**Constraints:**

- `1 <= s.length <= 10^5`
- `s[i]` is either `'0'` or `'1'`.

## Hints/Notes

- 2025/04/17 Q2
- preSum
- [Leetcode solution](https://leetcode.com/problems/flip-string-to-monotone-increasing/editorial)

## Solution

Language: **C++**

```C++
class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int n = s.size();
        vector<int> numZeros(n + 1, 0);
        for (int i = 0; i < n; i++) {
            numZeros[i + 1] = numZeros[i];
            if (s[i] == '0') {
                numZeros[i + 1] += 1;
            }
        }
        int res = INT_MAX;
        for (int i = 0; i <= n; i++) {
            // for each index, make it 0, and all afterwards 1
            int zero_before = numZeros[i], one_before = i - zero_before;
            int zero_after = numZeros[n] - zero_before, one_after = n - i - zero_after;
            res = min(res, one_before + zero_after);
        }
        return res;
    }
};
```
