---
title: 1004. Max Consecutive Ones III
categories: Leetcode
date: 2023-12-04 22:31:12
tags:
    - Array
    - Binary Search
    - Sliding Window
    - Prefix Sum
---

[1004\. Max Consecutive Ones III](https://leetcode.com/problems/max-consecutive-ones-iii/)

## Description

Difficulty: **Medium**

Related Topics: [Array](https://leetcode.com/tag/https://leetcode.com/tag/array//), [Binary Search](https://leetcode.com/tag/https://leetcode.com/tag/binary-search//), [Sliding Window](https://leetcode.com/tag/https://leetcode.com/tag/sliding-window//), [Prefix Sum](https://leetcode.com/tag/https://leetcode.com/tag/prefix-sum//)

Given a binary array `nums` and an integer `k`, return _the maximum number of consecutive_ `1`_'s in the array if you can flip at most_ `k` `0`'s.

**Example 1:**

```bash
Input: nums = [1,1,1,0,0,0,1,1,1,1,0], k = 2
Output: 6
Explanation: [1,1,1,0,0,1,1,1,1,1,1]
Bolded numbers were flipped from 0 to 1\. The longest subarray is underlined.
```

**Example 2:**

```bash
Input: nums = [0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1], k = 3
Output: 10
Explanation: [0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1]
Bolded numbers were flipped from 0 to 1\. The longest subarray is underlined.
```

**Constraints:**

* 1 <= nums.length <= 10<sup>5</sup>
* `nums[i]` is either `0` or `1`.
* `0 <= k <= nums.length`

## Hints/Notes

* sliding window

## Solution

Language: **C++**

```C++
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int left = 0, right = 0, res = 0, count = 0;
        while (right < nums.size()) {
            count += nums[right] == 0 ? 1 : 0;
            if (count > k) {
                while (left <= right && count > k) {
                    if (nums[left++] == 0) {
                        count--;
                    }
                }
            }
            res = max(res, right - left + 1);
            right++;
        }
        return res;
    }
};
```
