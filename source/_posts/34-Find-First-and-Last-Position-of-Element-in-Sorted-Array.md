---
title: 34. Find First and Last Position of Element in Sorted Array
categories: Leetcode
date: 2023-01-17 16:17:31
tags:
    - Array
    - Binary Search
---

[34\. Find First and Last Position of Element in Sorted Array](https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/)

## Description

Difficulty: **Medium**

Related Topics: [Array](https://leetcode.com/tag/array/), [Binary Search](https://leetcode.com/tag/binary-search/)

Given an array of integers `nums` sorted in non-decreasing order, find the starting and ending position of a given `target` value.

If `target` is not found in the array, return `[-1, -1]`.

You must write an algorithm with `O(log n)` runtime complexity.

**Example 1:**

```bash
Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]
```

**Example 2:**

```bash
Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]
```

**Example 3:**

```bash
Input: nums = [], target = 0
Output: [-1,-1]
```

**Constraints:**

* 0 <= nums.length <= 10<sup>5</sup>
* -10<sup>9</sup> <= nums[i] <= 10<sup>9</sup>
* `nums` is a non-decreasing array.
* -10<sup>9</sup> <= target <= 10<sup>9</sup>

## Hints/Notes

* Write different helper function to find left and right boundry

## Solution

Language: **C++**

```C++
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int left_bound = find_left_bound(nums, target);
        int right_bound = find_right_bound(nums, target);
        vector<int> res = {left_bound, right_bound}; 
        return res;
    }

    int find_left_bound(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1, res = -1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                res = mid;
                right = mid - 1;
            } else if (nums[mid] > target) {
                right = mid - 1;
            } else if (nums[mid] < target) {
                left = mid + 1;
            }
        }
        return res;
    }

    int find_right_bound(vector<int>& nums, int  target) {
        int left = 0, right = nums.size() - 1, res = -1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                res = mid;
                left = mid + 1;
            } else if (nums[mid] > target) {
                right = mid - 1;
            } else if (nums[mid] < target) {
                left = mid + 1;
            }
        }
        return res;
    }
};
```
