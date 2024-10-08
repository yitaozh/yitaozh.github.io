---
title: 3281. Maximize Score of Numbers in Ranges
categories: Leetcode
date: 2024-10-08 15:55:58
tags:
    - Array
    - Binary Search
    - Greedy
    - Sorting
---

[3281. Maximize Score of Numbers in Ranges](https://leetcode.com/problems/maximize-score-of-numbers-in-ranges/description/)

## Description

You are given an array of integers `start` and an integer `d`, representing `n` intervals `[start[i], start[i] + d]`.

You are asked to choose `n` integers where the `i^th` integer must belong to the `i^th` interval. The **score**  of the chosen integers is defined as the **minimum**  absolute difference between any two integers that have been chosen.

Return the **maximum**  possible score of the chosen integers.

**Example 1:**

```bash
Input: start = [6,0,3], d = 2

Output: 4
```

Explanation:

The maximum possible score can be obtained by choosing integers: 8, 0, and 4. The score of these chosen integers is `min(|8 - 0|, |8 - 4|, |0 - 4|)` which equals 4.

**Example 2:**

```bash
Input: start = [2,6,13,13], d = 5

Output: 5
```

Explanation:

The maximum possible score can be obtained by choosing integers: 2, 7, 13, and 18. The score of these chosen integers is `min(|2 - 7|, |2 - 13|, |2 - 18|, |7 - 13|, |7 - 18|, |13 - 18|)` which equals 5.

**Constraints:**

- `2 <= start.length <= 10^5`
- `0 <= start[i] <= 10^9`
- `0 <= d <= 10^9`

## Hints/Notes

- Weekly Contest 414

## Solution

Language: **C++**

```C++
class Solution {
public:
    int maxPossibleScore(vector<int>& start, int d) {
        sort(start.begin(), start.end());
        int n = start.size();
        int l = start[0], r = start[n - 1] + d;
        int tmp_res = (r - l) / (n - 1);
        for (int i = 0; i < n - 1; i++) {
            int left = start[i], right = start[i + 1] + d;
            tmp_res = min(tmp_res, right - left);
        }
        for (int res = tmp_res; res >= 0; res--) {
            int left = start[0];
            bool found = true;
            for (int i = 1; i < n; i++) {
                int end = start[i] + d;
                if (left + res > end) {
                    found = false;
                    break;
                }
                if (left + res <= start[i]) {
                    left = start[i];
                } else {
                    left += res;
                }
            }
            if (found) {
                return res;
            }
        }
        return 0;
    }
};
```
