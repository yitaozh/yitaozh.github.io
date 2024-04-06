---
title: 238. Product of Array Except Self
categories: Leetcode
date: 2023-11-12 23:29:12
tags:
    - Array
    - Prefix Sum
---

[238\. Product of Array Except Self](https://leetcode.com/problems/product-of-array-except-self/)

## Description

Difficulty: **Medium**

Related Topics: [Array](https://leetcode.com/tag/https://leetcode.com/tag/array//), [Prefix Sum](https://leetcode.com/tag/https://leetcode.com/tag/prefix-sum//)

Given an integer array `nums`, return _an array_ `answer` _such that_ `answer[i]` _is equal to the product of all the elements of_ `nums` _except_ `nums[i]`.

The product of any prefix or suffix of `nums` is **guaranteed** to fit in a **32-bit** integer.

You must write an algorithm that runs in `O(n)` time and without using the division operation.

**Example 1:**

```bash
Input: nums = [1,2,3,4]
Output: [24,12,8,6]
```

**Example 2:**

```bash
Input: nums = [-1,1,0,-3,3]
Output: [0,0,9,0,0]
```

**Constraints:**

* 2 <= nums.length <= 10<sup>5</sup>
* `-30 <= nums[i] <= 30`
* The product of any prefix or suffix of `nums` is **guaranteed** to fit in a **32-bit** integer.

**Follow up:** Can you solve the problem in `O(1)` extra space complexity? (The output array **does not** count as extra space for space complexity analysis.)

## Hints/Notes

* preSum

## Solution

Language: **C++**

```C++
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int size = nums.size();
        vector<int> preProduct(size + 1, 1);
        vector<int> sufProduct(size + 1, 1);
        for (int i = 0; i < size; i++) {
            preProduct[i + 1] = preProduct[i] * nums[i];
        }
        for (int i = size - 1; i >= 0; i--) {
            sufProduct[i] = sufProduct[i + 1] * nums[i];
        }
        vector<int> res(size, 0);
        for (int i = 0; i < size; i++) {
            res[i] = preProduct[i] * sufProduct[i + 1];
        }
        return res;
    }
};
```
