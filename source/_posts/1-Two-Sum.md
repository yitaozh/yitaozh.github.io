---
title: 1. Two Sum
categories: Leetcode
date: 2023-11-30 21:31:09
tags:
    - Array
    - Hash Table
---

[1\. Two Sum](https://leetcode.com/problems/two-sum/)

## Description

Difficulty: **Easy**

Related Topics: [Array](https://leetcode.com/tag/https://leetcode.com/tag/array//), [Hash Table](https://leetcode.com/tag/https://leetcode.com/tag/hash-table//)

Given an array of integers `nums` and an integer `target`, return _indices of the two numbers such that they add up to `target`_.

You may assume that each input would have **_exactly_ one solution**, and you may not use the _same_ element twice.

You can return the answer in any order.

**Example 1:**

```bash
Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
```

**Example 2:**

```bash
Input: nums = [3,2,4], target = 6
Output: [1,2]
```

**Example 3:**

```bash
Input: nums = [3,3], target = 6
Output: [0,1]
```

**Constraints:**

* 2 <= nums.length <= 10<sup>4</sup>
* -10<sup>9</sup> <= nums[i] <= 10<sup>9</sup>
* -10<sup>9</sup> <= target <= 10<sup>9</sup>
* **Only one valid answer exists.**

**Follow-up:** Can you come up with an algorithm that is less than O(n<sup>2</sup>)time complexity?

## Hints/Notes

* Use map

## Solution

Language: **C++**

```C++
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> m;
        for (int i = 0; i < nums.size(); i++) {
            if (m.count(target - nums[i])) {
                return {m[target - nums[i]], i};
            }
            m[nums[i]] = i;
        }
        return {-1, -1};
    }
};
```
