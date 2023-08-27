---
title: 327. Count of Range Sum
categories: Leetcode
date: 2023-08-26 01:21:40
tags:
    - Array
    - Binary Search
    - Divide and Conquer
    - Binary Indexed Tree
    - Segment Tree
    - Merge Sort
    - Ordered Set
---

# [327\. Count of Range Sum](https://leetcode.com/problems/count-of-range-sum/)

## Description

Difficulty: **Hard**

Related Topics: [Array](https://leetcode.com/tag/https://leetcode.com/tag/array//), [Binary Search](https://leetcode.com/tag/https://leetcode.com/tag/binary-search//), [Divide and Conquer](https://leetcode.com/tag/https://leetcode.com/tag/divide-and-conquer//), [Binary Indexed Tree](https://leetcode.com/tag/https://leetcode.com/tag/binary-indexed-tree//), [Segment Tree](https://leetcode.com/tag/https://leetcode.com/tag/segment-tree//), [Merge Sort](https://leetcode.com/tag/https://leetcode.com/tag/merge-sort//), [Ordered Set](https://leetcode.com/tag/https://leetcode.com/tag/ordered-set//)

Given an integer array `nums` and two integers `lower` and `upper`, return _the number of range sums that lie in_ `[lower, upper]` _inclusive_.

Range sum `S(i, j)` is defined as the sum of the elements in `nums` between indices `i` and `j` inclusive, where `i <= j`.

**Example 1:**

```bash
Input: nums = [-2,5,-1], lower = -2, upper = 2
Output: 3
Explanation: The three ranges are: [0,0], [2,2], and [0,2] and their respective sums are: -2, -1, 2.
```

**Example 2:**

```bash
Input: nums = [0], lower = 0, upper = 0
Output: 1
```

**Constraints:**

* 1 <= nums.length <= 10<sup>5</sup>
* -2<sup>31</sup> <= nums[i] <= 2<sup>31</sup> - 1
* -10<sup>5</sup> <= lower <= upper <= 10<sup>5</sup>
* The answer is **guaranteed** to fit in a **32-bit** integer.

## Hints/Notes

* Merge sort

## Solution

Language: **C++**

```C++
class Solution {
public:
    vector<long> tmp;
    vector<long> preSum;
    int count = 0;
    int lower_, upper_;

    int countRangeSum(vector<int>& nums, int lower, int upper) {
        int size = nums.size();
        tmp = vector<long>(size + 1, 0);
        preSum = vector<long>(size + 1, 0);
        for (int i = 0; i < size; i++) {
            preSum[i + 1] = preSum[i] + nums[i];
        }
        lower_ = lower;
        upper_ = upper;
        sort(preSum, 0, size);
        return count;
    }

    void sort(vector<long>& preSum, int low, int high) {
        if (low >= high) return;
        int mid = low + (high - low) / 2;
        sort(preSum, low, mid);
        sort(preSum, mid + 1, high);
        merge(preSum, low, mid, high);
    }

    void merge(vector<long>& preSum, int low, int mid, int high) {
        for (int i = low; i <= high; i++) {
            tmp[i] = preSum[i];
        }
        int start = mid + 1, end = mid + 1;

        for (int i = low; i <= mid; i++) {
            while (start <= high && preSum[start] - preSum[i] < lower_) {
                start++;
            }
            end = start;

            while (end <= high && preSum[end] - preSum[i] <= upper_) {
                end++;
            }
            count += end - start;
        }

        int p1 = low, p2 = mid + 1;
        for (int i = low; i <= high; i++) {
            if (p1 == mid + 1) {
                preSum[i] = tmp[p2++];
            } else if (p2 == high + 1) {
                preSum[i] = tmp[p1++];
            } else if (tmp[p1] > tmp[p2]) {
                preSum[i] = tmp[p2++];
            } else {
                preSum[i] = tmp[p1++];
            }
        }
    }
};
```
