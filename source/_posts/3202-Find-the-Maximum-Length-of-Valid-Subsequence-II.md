---
title: 3202. Find the Maximum Length of Valid Subsequence II
categories: Leetcode
date: 2024-07-03 23:42:23
tags:
    - Array
    - Dynamic Programming
---

[3202. Find the Maximum Length of Valid Subsequence II](https://leetcode.com/problems/find-the-maximum-length-of-valid-subsequence-ii/description/)

## Description

You are given an integer array `nums` and a **positive** integer `k`.

A subsequence `sub` of `nums` with length `x` is called **valid** if it satisfies:

- `(sub[0] + sub[1]) % k == (sub[1] + sub[2]) % k == ... == (sub[x - 2] + sub[x - 1]) % k.`

Return the length of the **longest**  **valid**  subsequence of `nums`.

**Example 1:**

```bash
Input: nums = [1,2,3,4,5], k = 2

Output: 5

Explanation:

The longest valid subsequence is `[1, 2, 3, 4, 5]`.
```

**Example 2:**

```bash
Input: nums = [1,4,2,3,1,4], k = 3

Output: 4

Explanation:

The longest valid subsequence is `[1, 4, 1, 4]`.
```

**Constraints:**

- `2 <= nums.length <= 10^3`
- `1 <= nums[i] <= 10^7`
- `1 <= k <= 10^3`

## Hints/Notes

- Weekly Contest 404

## Solution

Language: **C++**

```C++
class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        int res = 0;
        for (int i = 0; i < k; i++) {
            unordered_map<int, int> m;
            for (int num : nums) {
                int key = (i + k - num % k) % k;
                m[num % k] = m[key] + 1;
                res = max(res, m[num % k]);
            }
        }
        return res;
    }
};
```
