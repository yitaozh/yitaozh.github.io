---
title: 33. Search in Rotated Sorted Array
categories: Leetcode
date: 2023-12-02 17:42:18
tags:
    - Array
    - Binary Search
---

[33\. Search in Rotated Sorted Array](https://leetcode.com/problems/search-in-rotated-sorted-array/)

## Description

Difficulty: **Medium**

Related Topics: [Array](https://leetcode.com/tag/https://leetcode.com/tag/array//), [Binary Search](https://leetcode.com/tag/https://leetcode.com/tag/binary-search//)

There is an integer array `nums` sorted in ascending order (with **distinct** values).

Prior to being passed to your function, `nums` is **possibly rotated** at an unknown pivot index `k` (`1 <= k < nums.length`) such that the resulting array is `[nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]]` (**0-indexed**). For example, `[0,1,2,4,5,6,7]` might be rotated at pivot index `3` and become `[4,5,6,7,0,1,2]`.

Given the array `nums` **after** the possible rotation and an integer `target`, return _the index of_ `target` _if it is in_ `nums`_, or_ `-1` _if it is not in_ `nums`.

You must write an algorithm with `O(log n)` runtime complexity.

**Example 1:**

```bash
Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4
```

**Example 2:**

```bash
Input: nums = [4,5,6,7,0,1,2], target = 3
Output: -1
```

**Example 3:**

```bash
Input: nums = [1], target = 0
Output: -1
```

**Constraints:**

* `1 <= nums.length <= 5000`
* -10<sup>4</sup> <= nums[i] <= 10<sup>4</sup>
* All values of `nums` are **unique**.
* `nums` is an ascending array that is possibly rotated.
* -10<sup>4</sup> <= target <= 10<sup>4</sup>

## Hints/Notes

* 2023/11/19
* It's very easy to make mistakes on boundary
* [0x3F's solution](https://leetcode.cn/problems/search-in-rotated-sorted-array/solutions/1987503/by-endlesscheng-auuh/)(checked, but i think my solution is easier to understand)

## Solution

Language: **C++**

Inclusive range:

```C++
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            int mid = (right - left) / 2 + left;
            if (nums[mid] == target) {
                return mid;
            }
            if (nums[mid] >= nums[left]) {
                if (target >= nums[left] && target < nums[mid]) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            } else {
                if (target > nums[mid] && target <= nums[right]) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
        }
        return -1;
    }
};
```

```C++
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size();
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                return mid;
            }
            if (nums[mid] >= nums[left]) {
                if (target >= nums[left] && target < nums[mid]) {
                    right = mid;
                } else {
                    left = mid + 1;
                }
            } else {
                if (target > nums[mid] && target <= nums[right - 1]) {
                    left = mid + 1;
                } else {
                    right = mid;
                }
            }
        }
        return -1;
    }
};
```
