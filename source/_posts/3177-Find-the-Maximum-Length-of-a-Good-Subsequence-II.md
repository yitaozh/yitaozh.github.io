---
title: 3177. Find the Maximum Length of a Good Subsequence II
categories: Leetcode
date: 2024-06-14 14:01:16
tags:
    - Array
    - Hash Table
    - Dynamic Programming
---

[3177. Find the Maximum Length of a Good Subsequence II](https://leetcode.com/problems/find-the-maximum-length-of-a-good-subsequence-ii/description/)

## Description

You are given an integer array `nums` and a **non-negative**  integer `k`. A sequence of integers `seq` is called **good**  if there are **at most**  `k` indices `i` in the range `[0, seq.length - 2]` such that `seq[i] != seq[i + 1]`.

Return the **maximum**  possible length of a **good** subsequence of `nums`.

**Example 1:**

```bash
Input: nums = [1,2,1,1,3], k = 2

Output: 4

Explanation:

The maximum length subsequence is `[1,2,1,1,3]`.
```

**Example 2:**

```bash
Input: nums = [1,2,3,4,5,1], k = 0

Output: 2

Explanation:

The maximum length subsequence is `[1,2,3,4,5,1]`.
```

**Constraints:**

- `1 <= nums.length <= 5 * 10^3`
- `1 <= nums[i] <= 10^9`
- `0 <= k <= min(50, nums.length)`

## Hints/Notes

- Biweekly Contest 132
- dp

## Solution

Language: **C++**

```C++
class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        // dp[num][k]: the longest subsequence ending with num and with k
        // non-equal neighbors 
        // how to update dp[num][k]:
        //  dp[num][k] = dp[num][k - 1] + 1
        map<int, vector<int>> m;
        // the numbers in mx: mx1, mx2, mn
        vector<array<int, 3>> mx(k + 1, array<int, 3>());
        for (int num : nums) {
            if (!m.contains(num)) {
                m[num] = vector<int>(k + 1, 0);
            }
            for (int i = k; i >= 0; i--) {
                m[num][i]++;
                if (i) {
                    m[num][i] = max(m[num][i], mx[i - 1][0] + 1);
                }
                if (m[num][i] > mx[i][0]) {
                    if (num != mx[i][2]) {
                        mx[i][2] = num;
                        mx[i][1] = mx[i][0];
                    }
                    mx[i][0] = m[num][i];
                } else if (m[num][i] > mx[i][1] && num != mx[i][2]) {
                    mx[i][1] = m[num][i];
                }
            }
        }
        return mx[k][0];
    }
};
```
