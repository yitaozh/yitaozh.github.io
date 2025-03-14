---
title: 540. Single Element in a Sorted Array
categories: Leetcode
date: 2025-03-14 02:19:59
tags:
    - Array
    - Binary Search
---

[540. Single Element in a Sorted Array](https://leetcode.com/problems/single-element-in-a-sorted-array/description/)

## Description

You are given a sorted array consisting of only integers where every element appears exactly twice, except for one element which appears exactly once.

Return the single element that appears only once.

Your solution must run in `O(log n)` time and `O(1)` space.

**Example 1:**

```bash
Input: nums = [1,1,2,3,3,4,4,8,8]
Output: 2
```

**Example 2:**

```bash
Input: nums = [3,3,7,7,10,11,11]
Output: 10
```

**Constraints:**

- `1 <= nums.length <= 10^5`
- `0 <= nums[i] <= 10^5`

## Hints/Notes

- 2025/03/08 Q2
- binary search
- [0x3F's solution](https://leetcode.cn/problems/single-element-in-a-sorted-array/solutions/2983333/er-fen-xing-zhi-fen-xi-jian-ji-xie-fa-py-0rng/)

## Solution

Language: **C++**

```C++
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        int low = 0, high = n - 1;
        while (low < high) {
            int mid = (high + low) / 2;
            bool halvesAreEven = (high - mid) % 2 == 0;
            if (nums[mid + 1] == nums[mid]) {
                if (halvesAreEven) {
                    low = mid + 2;
                } else {
                    high = mid - 1;
                }
            } else if (nums[mid - 1] == nums[mid]) {
                if (halvesAreEven) {
                    high = mid - 2;
                } else {
                    low = mid + 1;
                }
            } else {
                return nums[mid];
            }
        }
        return nums[low];
    }
};
```
