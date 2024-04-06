---
title: 912. Sort an Array
categories: Leetcode
date: 2023-08-22 23:26:25
tags:
    - Array
    - Divide and Conquer
    - Sorting
    - Heap (Priority Queue)
    - Merge Sort
    - Bucket Sort
    - Radix Sort
    - Counting Sort
---

[912\. Sort an Array](https://leetcode.com/problems/sort-an-array/)

## Description

Difficulty: **Medium**

Related Topics: [Array](https://leetcode.com/tag/https://leetcode.com/tag/array//), [Divide and Conquer](https://leetcode.com/tag/https://leetcode.com/tag/divide-and-conquer//), [Sorting](https://leetcode.com/tag/https://leetcode.com/tag/sorting//), [Heap (Priority Queue)](https://leetcode.com/tag/https://leetcode.com/tag/heap-priority-queue//), [Merge Sort](https://leetcode.com/tag/https://leetcode.com/tag/merge-sort//), [Bucket Sort](https://leetcode.com/tag/https://leetcode.com/tag/bucket-sort//), [Radix Sort](https://leetcode.com/tag/https://leetcode.com/tag/radix-sort//), [Counting Sort](https://leetcode.com/tag/https://leetcode.com/tag/counting-sort//)

Given an array of integers `nums`, sort the array in ascending order and return it.

You must solve the problem **without using any built-in** functions in `O(nlog(n))` time complexity and with the smallest space complexity possible.

**Example 1:**

```bash
Input: nums = [5,2,3,1]
Output: [1,2,3,5]
Explanation: After sorting the array, the positions of some numbers are not changed (for example, 2 and 3), while the positions of other numbers are changed (for example, 1 and 5).
```

**Example 2:**

```bash
Input: nums = [5,1,1,2,0,0]
Output: [0,0,1,1,2,5]
Explanation: Note that the values of nums are not necessairly unique.
```

**Constraints:**

* 1 <= nums.length <= 5 * 10<sup>4</sup>
* -5 \* 10<sup>4</sup> <= nums[i] <= 5 \* 10<sup>4</sup>

## Hints/Notes

* merge sort

## Solution

Language: **C++**

```C++
class Solution {
public:
    vector<int> tmp;

    vector<int> sortArray(vector<int>& nums) {
        tmp = vector<int>(nums.size(), 0);
        sort(nums, 0, nums.size() - 1);
        return nums;
    }

    void sort(vector<int>& nums, int low, int high) {
        if (high <= low)
            return;

        int mid = low + (high - low) / 2;
        sort(nums, low, mid);
        sort(nums, mid + 1, high);
        merge(nums, low, mid, high);
    }

    void merge(vector<int>& nums, int low, int mid, int high) {
        for (int i = low; i <= high; i++) {
            tmp[i] = nums[i];
        }
        int i = low, j = mid + 1; 
        for (int index = low; index <= high; index++) {
            if (i == mid + 1) {
                nums[index] = tmp[j++];
            } else if (j == high + 1) {
                nums[index] = tmp[i++];
            } else if (tmp[i] < tmp[j]) {
                nums[index] = tmp[i++];
            } else {
                nums[index] = tmp[j++];
            }
        }
    }
};
```
