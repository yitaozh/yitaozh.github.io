---
title: 3356. Zero Array Transformation II
categories: Leetcode
date: 2024-12-03 17:26:45
tags:
    - Array
    - Binary Search
    - Prefix Sum
---

[3356. Zero Array Transformation II](https://leetcode.com/problems/zero-array-transformation-ii/description/)

## Description

You are given an integer array `nums` of length `n` and a 2D array `queries` where queries[i] = [l<sub>i</sub>, r<sub>i</sub>, val<sub>i</sub>].

Each `queries[i]` represents the following action on `nums`:

- Decrement the value at each index in the range [l<sub>i</sub>, r<sub>i</sub>] in `nums` by **at most**  `val<sub>i</sub>`.
- The amount by which each value is decremented can be chosen **independently**  for each index.

A **Zero Array**  is an array with all its elements equal to 0.

Return the **minimum**  possible **non-negative**  value of `k`, such that after processing the first `k` queries in **sequence** , `nums` becomes a **Zero Array** . If no such `k` exists, return -1.

**Example 1:**

<div class="example-block">
Input: nums = [2,0,2], queries = [[0,2,1],[0,2,1],[1,1,3]]

Output: 2

Explanation:

- **For i = 0 (l = 0, r = 2, val = 1):**

- Decrement values at indices `[0, 1, 2]` by `[1, 0, 1]` respectively.
- The array will become `[1, 0, 1]`.

- **For i = 1 (l = 0, r = 2, val = 1):**

- Decrement values at indices `[0, 1, 2]` by `[1, 0, 1]` respectively.
- The array will become `[0, 0, 0]`, which is a Zero Array. Therefore, the minimum value of `k` is 2.

**Example 2:**

<div class="example-block">
Input: nums = [4,3,2,1], queries = [[1,3,2],[0,2,1]]

Output: -1

Explanation:

- **For i = 0 (l = 1, r = 3, val = 2):**

- Decrement values at indices `[1, 2, 3]` by `[2, 2, 1]` respectively.
- The array will become `[4, 1, 0, 0]`.

- **For i = 1 (l = 0, r = 2, val = 1):**

- Decrement values at indices `[0, 1, 2]` by `[1, 1, 0]` respectively.
- The array will become `[3, 0, 0, 0]`, which is not a Zero Array.

**Constraints:**

- `1 <= nums.length <= 10^5`
- `0 <= nums[i] <= 5 * 10^5`
- `1 <= queries.length <= 10^5`
- `queries[i].length == 3`
- 0 <= l<sub>i</sub> <= r<sub>i</sub> < nums.length
- 1 <= val<sub>i</sub> <= 5

## Hints/Notes

- 2024/11/29
- binary search
- diff array
- [0x3F's solution](https://leetcode.cn/problems/zero-array-transformation-ii/solutions/2991505/liang-chong-fang-fa-er-fen-da-an-chai-fe-rcvg/)
- Weekly Contest 424

## Solution

Language: **C++**

```C++
class Solution {
public:
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int m = queries.size();
        int left = 0, right = m + 1;
        // [left, right), ending point: left = right
        // for all values >= right the return value is true
        while (left < right) {
            int mid = (left + right) / 2;
            if (check(mid, nums, queries)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return right == m + 1 ? -1 : left;
    }

    bool check(int k, vector<int> nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> diffs(n + 1, 0);
        for (int i = 0; i < k; i++) {
            auto& q = queries[i];
            int l = q[0], r = q[1], v = q[2];
            diffs[l] -= v;
            diffs[r + 1] += v;
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
