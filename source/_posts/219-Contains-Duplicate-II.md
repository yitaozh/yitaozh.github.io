---
title: 219. Contains Duplicate II
categories: Leetcode
date: 2023-12-05 23:00:42
tags:
    - Array
    - Hash Table
    - Sliding Window
---

[219\. Contains Duplicate II](https://leetcode.com/problems/contains-duplicate-ii/)

## Description

Difficulty: **Easy**

Related Topics: [Array](https://leetcode.com/tag/https://leetcode.com/tag/array//), [Hash Table](https://leetcode.com/tag/https://leetcode.com/tag/hash-table//), [Sliding Window](https://leetcode.com/tag/https://leetcode.com/tag/sliding-window//)

Given an integer array `nums` and an integer `k`, return `true` _if there are two **distinct indices**_ `i` _and_ `j` _in the array such that_ `nums[i] == nums[j]` _and_ `abs(i - j) <= k`.

**Example 1:**

```bash
Input: nums = [1,2,3,1], k = 3
Output: true
```

**Example 2:**

```bash
Input: nums = [1,0,1,1], k = 1
Output: true
```

**Example 3:**

```bash
Input: nums = [1,2,3,1,2,3], k = 2
Output: false
```

**Constraints:**

* 1 <= nums.length <= 10<sup>5</sup>
* -10<sup>9</sup> <= nums[i] <= 10<sup>9</sup>
* 0 <= k <= 10<sup>5</sup>

## Hints/Notes

* 2023/11/25
* sliding window
* [0x3F's solution](https://leetcode.cn/problems/contains-duplicate-ii/solutions/3041742/liang-chong-fang-fa-mei-ju-you-wei-hu-zu-kwjf/)(checked)

## Solution

Language: **C++**

```C++
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int left = 0, right = 0;
        map<int, int> m;
        while (right < nums.size()) {
            if (m[nums[right]] > 0) {
                return true;
            }
            m[nums[right]]++;
            right++;
            if (right - left > k) {
                m[nums[left]]--;
                left++;
            }
        }   
        return false;
    }
};
```
