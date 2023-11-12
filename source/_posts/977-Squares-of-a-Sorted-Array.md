---
title: 977. Squares of a Sorted Array
categories: Leetcode
date: 2023-11-11 23:13:34
tags:
    - Array
    - Two Pointers
    - Sorting
---

# [977\. Squares of a Sorted Array](https://leetcode.com/problems/squares-of-a-sorted-array/)

## Description

Difficulty: **Easy**

Related Topics: [Array](https://leetcode.com/tag/https://leetcode.com/tag/array//), [Two Pointers](https://leetcode.com/tag/https://leetcode.com/tag/two-pointers//), [Sorting](https://leetcode.com/tag/https://leetcode.com/tag/sorting//)

Given an integer array `nums` sorted in **non-decreasing** order, return _an array of **the squares of each number** sorted in non-decreasing order_.

**Example 1:**

```bash
Input: nums = [-4,-1,0,3,10]
Output: [0,1,9,16,100]
Explanation: After squaring, the array becomes [16,1,0,9,100].
After sorting, it becomes [0,1,9,16,100].
```

**Example 2:**

```bash
Input: nums = [-7,-3,2,3,11]
Output: [4,9,9,49,121]
```

**Constraints:**

* <span>1 <= nums.length <=</span> 10<sup>4</sup>
* -10<sup>4</sup> <= nums[i] <= 10<sup>4</sup>
* `nums` is sorted in **non-decreasing** order.

**Follow up:** Squaring each element and sorting the new array is very trivial, could you find an `O(n)` solution using a different approach?

## Hints/Notes

* two pointers, start and end of the array

## Solution

Language: **C++**

```C++
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int i = 0, j = nums.size() - 1, idx = nums.size() - 1;
        vector<int> res(nums.size(), 0);
        while (i <= j) {
            if (abs(nums[i]) < abs(nums[j])) {
                res[idx--] = nums[j] * nums[j];
                j--;
            } else {
                res[idx--] = nums[i] * nums[i];
                i++;
            }
        }
        return res;
    }
};
```
