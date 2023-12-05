---
title: 1658. Minimum Operations to Reduce X to Zero
categories: Leetcode
date: 2023-12-04 22:07:13
tags:
    - Array
    - Hash Table
    - Binary Search
    - Sliding Window
    - Prefix Sum
---

# [1658\. Minimum Operations to Reduce X to Zero](https://leetcode.com/problems/minimum-operations-to-reduce-x-to-zero/)

## Description

Difficulty: **Medium**

Related Topics: [Array](https://leetcode.com/tag/https://leetcode.com/tag/array//), [Hash Table](https://leetcode.com/tag/https://leetcode.com/tag/hash-table//), [Binary Search](https://leetcode.com/tag/https://leetcode.com/tag/binary-search//), [Sliding Window](https://leetcode.com/tag/https://leetcode.com/tag/sliding-window//), [Prefix Sum](https://leetcode.com/tag/https://leetcode.com/tag/prefix-sum//)

You are given an integer array `nums` and an integer `x`. In one operation, you can either remove the leftmost or the rightmost element from the array `nums` and subtract its value from `x`. Note that this **modifies** the array for future operations.

Return _the **minimum number** of operations to reduce_ `x` _to **exactly**_ `0` _if it is possible__, otherwise, return_ `-1`.

**Example 1:**

```bash
Input: nums = [1,1,4,2,3], x = 5
Output: 2
Explanation: The optimal solution is to remove the last two elements to reduce x to zero.
```

**Example 2:**

```bash
Input: nums = [5,6,7,8,9], x = 4
Output: -1
```

**Example 3:**

```bash
Input: nums = [3,2,20,1,1,3], x = 10
Output: 5
Explanation: The optimal solution is to remove the last three elements and the first two elements (5 operations in total) to reduce x to zero.
```

**Constraints:**

* 1 <= nums.length <= 10<sup>5</sup>
* 1 <= nums[i] <= 10<sup>4</sup>
* 1 <= x <= 10<sup>9</sup>

## Hints/Notes

* Sliding window

## Solution

Language: **C++**

```C++
class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int sum = 0, size = nums.size();
        for (int num : nums) {
            sum += num;
        }
        int target = sum - x, left = 0, right = 0, res = INT_MAX;
        sum = 0;
        while (right < nums.size()) {
            sum += nums[right];
            if (sum > target) {
                while (sum > target && left <= right) {
                    sum -= nums[left];
                    left++;
                }
            }
            if (sum == target) {
                res = min(res, size - right + left - 1);
            }
            right++; 
        }
        return res == INT_MAX ? -1 : res;
    }
};
```
