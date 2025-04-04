---
title: 153. Find Minimum in Rotated Sorted Array
categories: Leetcode
date: 2024-12-30 12:45:34
tags:
    - Array
    - Binary Search
---

[153. Find Minimum in Rotated Sorted Array](https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/description/?envType=problem-list-v2&envId=plakya4j)

## Description

Suppose an array of length `n` sorted in ascending order is **rotated**  between `1` and `n` times. For example, the array `nums = [0,1,2,4,5,6,7]` might become:

- `[4,5,6,7,0,1,2]` if it was rotated `4` times.
- `[0,1,2,4,5,6,7]` if it was rotated `7` times.

Notice that **rotating**  an array `[a[0], a[1], a[2], ..., a[n-1]]` 1 time results in the array `[a[n-1], a[0], a[1], a[2], ..., a[n-2]]`.

Given the sorted rotated array `nums` of **unique**  elements, return the minimum element of this array.

You must write an algorithm that runs in`O(log n) time`.

**Example 1:**

```bash
Input: nums = [3,4,5,1,2]
Output: 1
Explanation: The original array was [1,2,3,4,5] rotated 3 times.
```

**Example 2:**

```bash
Input: nums = [4,5,6,7,0,1,2]
Output: 0
Explanation: The original array was [0,1,2,4,5,6,7] and it was rotated 4 times.
```

**Example 3:**

```bash
Input: nums = [11,13,15,17]
Output: 11
Explanation: The original array was [11,13,15,17] and it was rotated 4 times.
```

**Constraints:**

- `n == nums.length`
- `1 <= n <= 5000`
- `-5000 <= nums[i] <= 5000`
- All the integers of `nums` are **unique** .
- `nums` is sorted and rotated between `1` and `n` times.

## Hints/Notes

- 2024/12/30
- binary search
- [0x3F's solution](https://leetcode.cn/problems/find-minimum-in-rotated-sorted-array/solutions/1987499/by-endlesscheng-owgd/)(checked)

## Solution

Language: **C++**

```C++
class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0, right = nums.size(), end = nums[right - 1];
        // the checking range: [left, right)
        // nums[right, n) is always less than end
        // nums[0, left - 1] is always bigger than end
        while (left < right) {
            int mid = (left + right) / 2;
            if (nums[mid] > end) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return nums[right];
    }
};
```
