---
title: 3185. Count Pairs That Form a Complete Day II
categories: Leetcode
date: 2024-06-19 00:35:44
tags:
    - Array
    - Hash Table
    - Counting
---

[3185. Count Pairs That Form a Complete Day II](https://leetcode.com/problems/count-pairs-that-form-a-complete-day-ii/description/)

## Description

Given an integer array `hours` representing times in **hours** , return an integer denoting the number of pairs `i`, `j` where `i < j` and `hours[i] + hours[j]` forms a **complete day** .

A **complete day**  is defined as a time duration that is an **exact**  **multiple**  of 24 hours.

For example, 1 day is 24 hours, 2 days is 48 hours, 3 days is 72 hours, and so on.

**Example 1:**

```bash
Input: hours = [12,12,30,24,24]

Output: 2

Explanation: The pairs of indices that form a complete day are `(0, 1)` and `(3, 4)`.
```

**Example 2:**

```bash
Input: hours = [72,48,24,3]

Output: 3

Explanation: The pairs of indices that form a complete day are `(0, 1)`, `(0, 2)`, and `(1, 2)`.
```

**Constraints:**

- `1 <= hours.length <= 5 * 10^5`
- `1 <= hours[i] <= 10^9`

## Hints/Notes

- 2024/04/15
- [0x3F's solution](https://leetcode.cn/problems/count-pairs-that-form-a-complete-day-ii/solution/tao-lu-mei-ju-you-wei-hu-zuo-pythonjavac-3vhv/)
- Weekly Contest 402

## Solution

Language: **C++**

```C++
class Solution {
public:
    long long countCompleteDayPairs(vector<int>& hours) {
        long long res = 0;
        map<int, long long> m;
        for (int hour: hours) {
            int h = (24 - hour % 24) % 24;
            res += m[h];
            m[hour % 24]++;
        }
        return res;
    }
};
```
