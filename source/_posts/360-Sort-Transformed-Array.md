---
title: 360. Sort Transformed Array
categories: Leetcode
date: 2023-11-11 23:36:09
tags:
    - Array
    - Math
    - Two Pointers
    - Sorting
---

[360\. Sort Transformed Array](https://leetcode.com/problems/sort-transformed-array/)

## Description

Difficulty: **Medium**

Related Topics: [Array](https://leetcode.com/tag/https://leetcode.com/tag/array//), [Math](https://leetcode.com/tag/https://leetcode.com/tag/math//), [Two Pointers](https://leetcode.com/tag/https://leetcode.com/tag/two-pointers//), [Sorting](https://leetcode.com/tag/https://leetcode.com/tag/sorting//)

Given a **sorted** integer array `nums` and three integers `a`, `b` and `c`, apply a quadratic function of the form f(x) = ax<sup>2</sup> + bx + c to each element `nums[i]` in the array, and return _the array in a sorted order_.

**Example 1:**

```bash
Input: nums = [-4,-2,2,4], a = 1, b = 3, c = 5
Output: [3,9,15,33]
```

**Example 2:**

```bash
Input: nums = [-4,-2,2,4], a = -1, b = 3, c = 5
Output: [-23,-5,1,7]
```

**Constraints:**

* `1 <= nums.length <= 200`
* `-100 <= nums[i], a, b, c <= 100`
* `nums` is sorted in **ascending** order.

**Follow up:** Could you solve it in `O(n)` time?

## Hints/Notes

* Two pointers, start and end of the array

## Solution

Language: **C++**

```C++
class Solution {
public:
    vector<int> sortTransformedArray(vector<int>& nums, int a, int b, int c) {
        int i = 0, j = nums.size() - 1, idx = 0;
        if (a >= 0) {
            idx = nums.size() - 1;
        }
        vector<int> res(nums.size(), 0);
        while (i <= j) {
            int v1 = f(a, b, c, nums[i]);
            int v2 = f(a, b, c, nums[j]);
            if (a < 0) {
                if (v1 < v2) {
                    res[idx++] = v1;
                    i++;
                } else {
                    res[idx++] = v2;
                    j--;
                }
            } else {
                if (v1 < v2) {
                    res[idx--] = v2;
                    j--;
                } else {
                    res[idx--] = v1;
                    i++;
                }
            }
        }
        return res;
    }

    int f(int a, int b, int c, int x) {
        return a * x * x + b * x + c;
    }
};
```
