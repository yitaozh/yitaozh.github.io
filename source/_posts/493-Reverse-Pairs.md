---
title: 493. Reverse Pairs
categories: Leetcode
date: 2023-08-25 00:29:56
tags:
    - Array
    - Binary Search
    - Divide and Conquer
    - Binary Indexed Tree
    - Segment Tree
    - Merge Sort
    - Ordered Set
---

[493\. Reverse Pairs](https://leetcode.com/problems/reverse-pairs/)

## Description

Difficulty: **Hard**

Related Topics: [Array](https://leetcode.com/tag/https://leetcode.com/tag/array//), [Binary Search](https://leetcode.com/tag/https://leetcode.com/tag/binary-search//), [Divide and Conquer](https://leetcode.com/tag/https://leetcode.com/tag/divide-and-conquer//), [Binary Indexed Tree](https://leetcode.com/tag/https://leetcode.com/tag/binary-indexed-tree//), [Segment Tree](https://leetcode.com/tag/https://leetcode.com/tag/segment-tree//), [Merge Sort](https://leetcode.com/tag/https://leetcode.com/tag/merge-sort//), [Ordered Set](https://leetcode.com/tag/https://leetcode.com/tag/ordered-set//)

Given an integer array `nums`, return _the number of **reverse pairs** in the array_.

A **reverse pair** is a pair `(i, j)` where:

* `0 <= i < j < nums.length` and
* `nums[i] > 2 * nums[j]`.

**Example 1:**

```bash
Input: nums = [1,3,2,3,1]
Output: 2
Explanation: The reverse pairs are:
(1, 4) --> nums[1] = 3, nums[4] = 1, 3 > 2 * 1
(3, 4) --> nums[3] = 3, nums[4] = 1, 3 > 2 * 1
```

**Example 2:**

```bash
Input: nums = [2,4,3,5,1]
Output: 3
Explanation: The reverse pairs are:
(1, 4) --> nums[1] = 4, nums[4] = 1, 4 > 2 * 1
(2, 4) --> nums[2] = 3, nums[4] = 1, 3 > 2 * 1
(3, 4) --> nums[3] = 5, nums[4] = 1, 5 > 2 * 1
```

**Constraints:**

* 1 <= nums.length <= 5 * 10<sup>4</sup>
* -2<sup>31</sup> <= nums[i] <= 2<sup>31</sup> - 1

## Hints/Notes

* merge sort
* improve time complexity

## Solution

Language: **C++**

```C++
class Solution {
public:
    int count = 0;
    vector<int> tmp;

    int reversePairs(vector<int>& nums) {
        int size = nums.size();
        tmp = vector(size, 0);
        sort(nums, 0, size - 1);
        return count;
    }

    void sort(vector<int>& nums, int low, int high) {
        if (low >= high) return;
        int mid = low + (high - low) / 2;
        sort(nums, low, mid);
        sort(nums, mid + 1, high);
        merge(nums, low, mid, high);
    }

    void merge(vector<int>& nums, int low, int mid, int high) {
        for (int i = low; i <= high; i++) {
            tmp[i] = nums[i];
        }

        int end = mid + 1;
        for (int i = low; i <= mid; i++) {
            while (end <= high && ((long)nums[i] > (long)nums[end] * 2)) {
                end++;
            }
            count += end - mid - 1;
        }

        int p1 = low, p2 = mid + 1, index = low;
        while (index <= high) {
            if (p1 == mid + 1) {
                nums[index++] = tmp[p2++];
            } else if (p2 == high + 1) {
                nums[index++] = tmp[p1++];
            } else if (tmp[p1] > tmp[p2]) {
                nums[index++] = tmp[p2++];
            } else {
                nums[index++] = tmp[p1++];
            }
        }
    }
};
```
