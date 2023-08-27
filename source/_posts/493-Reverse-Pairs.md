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

# [](https://leetcode.com/problems/reverse-pairs/description/)

## Description

Difficulty: **undefined**

Related Topics: [Array](https://leetcode.com/tag/https://leetcode.com/tag/array//), [Binary Search](https://leetcode.com/tag/https://leetcode.com/tag/binary-search//), [Divide and Conquer](https://leetcode.com/tag/https://leetcode.com/tag/divide-and-conquer//), [Binary Indexed Tree](https://leetcode.com/tag/https://leetcode.com/tag/binary-indexed-tree//), [Segment Tree](https://leetcode.com/tag/https://leetcode.com/tag/segment-tree//), [Merge Sort](https://leetcode.com/tag/https://leetcode.com/tag/merge-sort//), [Ordered Set](https://leetcode.com/tag/https://leetcode.com/tag/ordered-set//)

## Hints/Notes

* merge sort
* improve time complixity

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
