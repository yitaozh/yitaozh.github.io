---
title: 503. Next Greater Element II
categories: Leetcode
date: 2023-09-10 23:45:52
tags:
    - Array
    - Stack
    - Monotonic Stack
---

# [503\. Next Greater Element II](https://leetcode.com/problems/next-greater-element-ii/)

## Description

Difficulty: **Medium**

Related Topics: [Array](https://leetcode.com/tag/https://leetcode.com/tag/array//), [Stack](https://leetcode.com/tag/https://leetcode.com/tag/stack//), [Monotonic Stack](https://leetcode.com/tag/https://leetcode.com/tag/monotonic-stack//)

Given a circular integer array `nums` (i.e., the next element of `nums[nums.length - 1]` is `nums[0]`), return _the **next greater number** for every element in_ `nums`.

The **next greater number** of a number `x` is the first greater number to its traversing-order next in the array, which means you could search circularly to find its next greater number. If it doesn't exist, return `-1` for this number.

**Example 1:**

```bash
Input: nums = [1,2,1]
Output: [2,-1,2]
Explanation: The first 1's next greater number is 2;
The number 2 can't find next greater number.
The second 1's next greater number needs to search circularly, which is also 2.
```

**Example 2:**

```bash
Input: nums = [1,2,3,4,3]
Output: [2,3,4,-1,4]
```

**Constraints:**

* 1 <= nums.length <= 10<sup>4</sup>
* -10<sup>9</sup> <= nums[i] <= 10<sup>9</sup>

## Hints/Notes

* Monotonic Stack

## Solution

Language: **C++**

```C++
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int size = nums.size();
        vector<int> res(size, 0);
        stack<int> greater;
        for (int i = size * 2 - 1; i >= 0; i--) {
            while (!greater.empty() && greater.top() <= nums[i % size]) {
                greater.pop();
            }
            res[i % size] = greater.empty() ? -1 : greater.top();
            greater.push(nums[i % size]);
        }
        return res;
    }
};
```
