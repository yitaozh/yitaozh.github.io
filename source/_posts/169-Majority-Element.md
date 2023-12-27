---
title: 169. Majority Element
categories: Leetcode
date: 2023-12-26 21:48:58
tags:
    - Array
    - Hash Table
    - Divide and Conquer
    - Sorting
    - Counting
---

# [169\. Majority Element](https://leetcode.com/problems/majority-element/)

## Description

Difficulty: **Easy**

Related Topics: [Array](https://leetcode.com/tag/https://leetcode.com/tag/array//), [Hash Table](https://leetcode.com/tag/https://leetcode.com/tag/hash-table//), [Divide and Conquer](https://leetcode.com/tag/https://leetcode.com/tag/divide-and-conquer//), [Sorting](https://leetcode.com/tag/https://leetcode.com/tag/sorting//), [Counting](https://leetcode.com/tag/https://leetcode.com/tag/counting//)

Given an array `nums` of size `n`, return _the majority element_.

The majority element is the element that appears more than `⌊n / 2⌋` times. You may assume that the majority element always exists in the array.

**Example 1:**

```bash
Input: nums = [3,2,3]
Output: 3
```

**Example 2:**

```bash
Input: nums = [2,2,1,1,1,2,2]
Output: 2
```

**Constraints:**

* `n == nums.length`
* 1 <= n <= 5 * 10<sup>4</sup>
* -10<sup>9</sup> <= nums[i] <= 10<sup>9</sup>

**Follow-up:** Could you solve the problem in linear time and in `O(1)` space?

## Solution

Language: **C++**

```C++
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int target = nums[0];
        int count = 0;
        for (int num : nums) {
            if (count == 0) {
                target = num;
                count++;
            } else if (num == target) {
                count++;
            } else {
                count--;
            }
        }
        return target;
    }
};
```
