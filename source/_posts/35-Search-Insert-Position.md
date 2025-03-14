---
title: 35. Search Insert Position
categories: Leetcode
date: 2025-03-14 02:07:41
tags:
    - Array
    - Binary Search
---

[35. Search Insert Position](https://leetcode.com/problems/search-insert-position/description/)

## Description

Given a sorted array of distinct integers and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You mustwrite an algorithm with`O(log n)` runtime complexity.

**Example 1:**

```bash
Input: nums = [1,3,5,6], target = 5
Output: 2
```

**Example 2:**

```bash
Input: nums = [1,3,5,6], target = 2
Output: 1
```

**Example 3:**

```bash
Input: nums = [1,3,5,6], target = 7
Output: 4
```

**Constraints:**

- `1 <= nums.length <= 10^4`
- `-10^4 <= nums[i] <= 10^4`
- `nums` contains **distinct**  values sorted in **ascending**  order.
- `-10^4 <= target <= 10^4`

## Hints/Notes

- 2025/03/06 Q3
- binary sort
- [0x3F's solution](https://leetcode.cn/problems/search-insert-position/solutions/2023391/er-fen-cha-zhao-zong-shi-xie-bu-dui-yi-g-nq23/)

## Solution

Language: **C++**

```C++
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = -1, right = nums.size();
        while (left + 1 < right) {
            int mid = (right + left) / 2;
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] < target) {
                left = mid;
            } else {
                right = mid;
            }
        }
        return left + 1;
    }
};
```
