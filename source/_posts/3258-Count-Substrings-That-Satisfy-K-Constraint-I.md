---
title: 3258. Count Substrings That Satisfy K-Constraint I
categories: Leetcode
date: 2024-10-03 23:44:22
tags:
    - String
    - Sliding Window
---

[3258. Count Substrings That Satisfy K-Constraint I](https://leetcode.com/problems/count-substrings-that-satisfy-k-constraint-i/description/)

## Description

You are given a **binary**  string `s` and an integer `k`.

A **binary string**  satisfies the **k-constraint**  if **either**  of the following conditions holds:

- The number of `0`'s in the string is at most `k`.
- The number of `1`'s in the string is at most `k`.

Return an integer denoting the number of substrings of `s` that satisfy the **k-constraint** .

**Example 1:**

```bash
Input: s = "10101", k = 1

Output: 12
```

Explanation:

Every substring of `s` except the substrings `"1010"`, `"10101"`, and `"0101"` satisfies the k-constraint.

**Example 2:**

```bash
Input: s = "1010101", k = 2

Output: 25
```

Explanation:

Every substring of `s` except the substrings with a length greater than 5 satisfies the k-constraint.

**Example 3:**

```bash
Input: s = "11111", k = 1

Output: 15
```

Explanation:

All substrings of `s` satisfy the k-constraint.

**Constraints:**

- `1 <= s.length <= 50`
- `1 <= k <= s.length`
- `s[i]` is either `'0'` or `'1'`.

## Hints/Notes

- sliding window

## Solution

Language: **C++**

```C++
class Solution {
public:
    int countKConstraintSubstrings(string s, int k) {
        int res = 0, left = 0;
        vector<int> count(2, 0);
        for (int right = 0; right < s.size(); right++) {
            int val = s[right] - '0';
            count[val % 2]++;
            while (count[0] > k && count[1] > k) {
                val = s[left] - '0';
                count[val % 2]--;
                left++;
            }
            res += right + 1 - left;
        }
        return res;
    }
};
```
