---
title: 3355. Zero Array Transformation I
categories: Leetcode
date: 2024-12-03 17:23:11
tags:
    - Array
    - Prefix Sum
---

[3355. Zero Array Transformation I](https://leetcode.com/problems/zero-array-transformation-i/description/)

## Description

You are given an integer array `nums` of length `n` and a 2D array `queries`, where queries[i] = [l<sub>i</sub>, r<sub>i</sub>].

For each `queries[i]`:

- Select a subset of indices within the range [l<sub>i</sub>, r<sub>i</sub>] in `nums`.
- Decrement the values at the selected indices by 1.

A **Zero Array**  is an array where all elements are equal to 0.

Return `true` if it is possible to transform `nums` into a **Zero Array** after processing all the queries sequentially, otherwise return `false`.

**Example 1:**

```bash
Input: nums = [1,0,1], queries = [[0,2]]

Output: true
```

Explanation:

- **For i = 0:**

  - Select the subset of indices as `[0, 2]` and decrement the values at these indices by 1.
  - The array will become `[0, 0, 0]`, which is a Zero Array.

**Example 2:**

```bash
Input: nums = [4,3,2,1], queries = [[1,3],[0,2]]

Output: false
```

Explanation:

- **For i = 0:**

  - Select the subset of indices as `[1, 2, 3]` and decrement the values at these indices by 1.
  - The array will become `[4, 2, 1, 0]`.

- **For i = 1:**

  - Select the subset of indices as `[0, 1, 2]` and decrement the values at these indices by 1.
  - The array will become `[3, 1, 0, 0]`, which is not a Zero Array.

**Constraints:**

- `1 <= nums.length <= 10^5`
- `0 <= nums[i] <= 10^5`
- `1 <= queries.length <= 10^5`
- `queries[i].length == 2`
- 0 <= l<sub>i</sub> <= r<sub>i</sub> < nums.length

## Hints/Notes

- 2024/11/28
- diff array
- [0x3F's solution](https://leetcode.cn/problems/zero-array-transformation-i/solutions/2991455/mo-ban-chai-fen-shu-zu-pythonjavacgo-by-i4axs/)(checked)
- Weekly Contest 424

## Solution

Language: **C++**

```C++
class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> diffs(n + 1, 0);
        for (auto& q : queries) {
            int l = q[0], r = q[1];
            diffs[l] -= 1;
            diffs[r + 1] += 1;
        }
        partial_sum(diffs.begin(), diffs.end(), diffs.begin());
        for (int i = 0; i < n; i++) {
            nums[i] = nums[i] + diffs[i];
            if (nums[i] > 0) {
                return false;
            }

        }
        return true;
    }
};
```
