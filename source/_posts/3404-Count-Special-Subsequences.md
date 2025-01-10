---
title: 3404. Count Special Subsequences
categories: Leetcode
date: 2025-01-10 17:01:01
tags:
    - Array
    - Hash Table
    - Math
    - Enumeration
---

[3404. Count Special Subsequences](https://leetcode.com/problems/count-special-subsequences/description/)

## Description

You are given an array `nums` consisting of positive integers.

A **special subsequence**  is defined as a subsequence of length 4, represented by indices `(p, q, r, s)`, where `p < q < r < s`. This subsequence **must**  satisfy the following conditions:

- `nums[p] * nums[r] == nums[q] * nums[s]`
- There must be at least **one**  element between each pair of indices. In other words, `q - p > 1`, `r - q > 1` and `s - r > 1`.

Return the number of different **special**  **subsequences**  in `nums`.

**Example 1:**

```bash
Input: nums = [1,2,3,4,3,6,1]

Output: 1
```

Explanation:

There is one special subsequence in `nums`.

- `(p, q, r, s) = (0, 2, 4, 6)`:

- This corresponds to elements `(1, 3, 3, 1)`.
- `nums[p] * nums[r] = nums[0] * nums[4] = 1 * 3 = 3`
- `nums[q] * nums[s] = nums[2] * nums[6] = 3 * 1 = 3`

**Example 2:**

```bash
Input: nums = [3,4,3,4,3,4,3,4]

Output: 3
```

Explanation:

There are three special subsequences in `nums`.

- `(p, q, r, s) = (0, 2, 4, 6)`:

- This corresponds to elements `(3, 3, 3, 3)`.
- `nums[p] * nums[r] = nums[0] * nums[4] = 3 * 3 = 9`
- `nums[q] * nums[s] = nums[2] * nums[6] = 3 * 3 = 9`

- `(p, q, r, s) = (1, 3, 5, 7)`:

- This corresponds to elements `(4, 4, 4, 4)`.
- `nums[p] * nums[r] = nums[1] * nums[5] = 4 * 4 = 16`
- `nums[q] * nums[s] = nums[3] * nums[7] = 4 * 4 = 16`

- `(p, q, r, s) = (0, 2, 5, 7)`:

- This corresponds to elements `(3, 3, 4, 4)`.
- `nums[p] * nums[r] = nums[0] * nums[5] = 3 * 4 = 12`
- `nums[q] * nums[s] = nums[2] * nums[7] = 3 * 4 = 12`

**Constraints:**

- `7 <= nums.length <= 1000`
- `1 <= nums[i] <= 1000`

## Hints/Notes

- 2025/01/11
- prefix/suffix
- [0x3F's solution](https://leetcode.cn/problems/count-special-subsequences/solutions/3033284/shi-zi-bian-xing-qian-hou-zhui-fen-jie-p-ts6n/)(checked)
- Weekly Contest 430

## Solution

Language: **C++**

```C++
class Solution {
public:
    long long numberOfSubsequences(vector<int>& nums) {
        int n = nums.size();
        unordered_map<double, int> suf;
        // minimum index:
        // p, q, r, s
        // 0, 2, 4, 6
        // p / q = s / r
        for (int i = 4; i < n; i++) {
            for (int j = i + 2; j < n; j++) {
                suf[nums[j] * 1.0 / nums[i]]++;
            }
        }
        long long res = 0;
        for (int j = 2; j < n; j++) {
            for (int i = 0; i <= j - 2; i++) {
                res += suf[nums[i] * 1.0 / nums[j]];
            }
            // assume j is increasing to 3, then we need to remove all pairs with r = 4
            for (int i = j + 4; i < n; i++) {
                suf[nums[i] * 1.0 / nums[j + 2]]--;
            }
        }
        return res;
    }
};
```
