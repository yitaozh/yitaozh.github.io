---
title: 3165. Maximum Sum of Subsequence With Non-adjacent Elements
categories: Leetcode
date: 2024-05-30 12:27:59
tags:
    - Array
    - Divide and Conquer
    - Dynamic Programming
    - Segment Tree
---

[3165. Maximum Sum of Subsequence With Non-adjacent Elements](https://leetcode.com/problems/maximum-sum-of-subsequence-with-non-adjacent-elements/description/)

You are given an array `nums` consisting of integers. You are also given a 2D array `queries`, where `queries[i] = [pos<sub>i</sub>, x<sub>i</sub>]`.

For query `i`, we first set nums[pos<sub>i</sub>] equal to x<sub>i</sub>, then we calculate the answer to query `i` which is the **maximum**  sum of a subsequence of `nums` where **no two adjacent elements are selected** .

Return the sum of the answers to all queries.

Since the final answer may be very large, return it **modulo**  `10^9 + 7`.

A **subsequence**  is an array that can be derived from another array by deleting some or no elements without changing the order of the remaining elements.

**Example 1:**

```bash
Input: nums = [3,5,9], queries = [[1,-2],[0,-3]]

Output: 21

Explanation:<br>
After the 1^st query, `nums = [3,-2,9]` and the maximum sum of a subsequence with non-adjacent elements is `3 + 9 = 12`.<br>
After the 2^nd query, `nums = [-3,-2,9]` and the maximum sum of a subsequence with non-adjacent elements is 9.
```

**Example 2:**

```bash
Input: nums = [0,-1], queries = [[0,-5]]

Output: 0

Explanation:<br>
After the 1^st query, `nums = [-5,-1]` and the maximum sum of a subsequence with non-adjacent elements is 0 (choosing an empty subsequence).
```

**Constraints:**

- `1 <= nums.length <= 5 * 10^4`
- `-10^5 <= nums[i] <= 10^5`
- `1 <= queries.length <= 5 * 10^4`
- `queries[i] == [pos<sub>i</sub>, x<sub>i</sub>]`
- `0 <= pos<sub>i</sub> <= nums.length - 1`
- `-10^5 <= x<sub>i</sub> <= 10^5`

## Hints/Notes

- Weekly Contest 399
- Segment Tree

## Solution

Language: **C++**

```C++
class Solution {
public:
    vector<array<unsigned, 4>> t;

    int maximumSumSubsequence(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        t.resize(2 << (32 - __builtin_clz(n)));
        build(nums, 1, 0, n - 1);
        long long res = 0;
        for (auto& q : queries) {
            update(1, 0, n - 1, q[0], q[1]);
            res += t[1][3];
        }
        return res % 1'000'000'007;
    }

    void update(int o, int l, int r, int i, int val) {
        if (l == r) {
            t[o][3] = max(val, 0);
            return;
        }
        int m = (r - l) / 2 + l;
        if (i <= m) {
            update(o * 2, l, m, i, val);
        } else {
            update(o * 2 + 1, m + 1, r, i, val);
        }
        maintain(o);
    }

    void build(vector<int>& nums, int o, int l, int r) {
        if (l == r) {
            t[o][3] = max(nums[l], 0);
            return;
        }
        int m = (r - l) / 2 + l;
        build(nums, o * 2, l, m);
        build(nums, o * 2 + 1, m + 1, r);
        maintain(o);
    }

    void maintain(int o) {
        auto &a = t[o * 2], b = t[o * 2 + 1];
        t[o] = {
            // 0: 00, 1: 01
            // 2: 10, 3: 11
            max(a[0] + b[2], a[1] + b[0]),
            max(a[0] + b[3], a[1] + b[1]),
            max(a[2] + b[2], a[3] + b[0]),
            max(a[2] + b[3], a[3] + b[1]),
        };
    }
};
```
