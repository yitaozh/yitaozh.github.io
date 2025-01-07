---
title: 215. Kth Largest Element in an Array
categories: Leetcode
date: 2023-08-28 00:32:20
tags:
    - Array
    - Divide and Conquer
    - Sorting
    - Heap (Priority Queue)
    - Quickselect
---

[215\. Kth Largest Element in an Array](https://leetcode.com/problems/kth-largest-element-in-an-array/)

## Description

Difficulty: **Medium**

Related Topics: [Array](https://leetcode.com/tag/https://leetcode.com/tag/array//), [Divide and Conquer](https://leetcode.com/tag/https://leetcode.com/tag/divide-and-conquer//), [Sorting](https://leetcode.com/tag/https://leetcode.com/tag/sorting//), [Heap (Priority Queue)](https://leetcode.com/tag/https://leetcode.com/tag/heap-priority-queue//), [Quickselect](https://leetcode.com/tag/https://leetcode.com/tag/quickselect//)

Given an integer array `nums` and an integer `k`, return _the_ k<sup>th</sup> _largest element in the array_.

Note that it is the k<sup>th</sup> largest element in the sorted order, not the k<sup>th</sup> distinct element.

Can you solve it without sorting?

**Example 1:**

```bash
Input: nums = [3,2,1,5,6,4], k = 2
Output: 5
```

**Example 2:**

```bash
Input: nums = [3,2,3,1,2,4,5,5,6], k = 4
Output: 4
```

**Constraints:**

* 1 <= k <= nums.length <= 10<sup>5</sup>
* -10<sup>4</sup> <= nums[i] <= 10<sup>4</sup>

## Hints/Notes

* 2023/08/27
* Priority queue
* Quick select
* No solution from 0x3F

## Solution

Language: **C++**

Quick select

```C++
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        return find(nums, nums.size() - k + 1);
    }

    int find(vector<int>& nums, int k) {
        int pivot = nums[rand() % nums.size()];
        vector<int> left, mid, right;
        for (int num : nums) {
            if (num < pivot) {
                left.push_back(num);
            } else if (num > pivot) {
                right.push_back(num);
            } else {
                mid.push_back(num);
            }
        }
        if (left.size() >= k) {
            return find(left, k);
        }
        if (left.size() + mid.size() < k) {
            return find(right, k - left.size() - mid.size());
        }
        return pivot;
    }
};
```

```C++
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int num : nums) {
            pq.push(num);
            if (pq.size() > k) {
                pq.pop();
            }
        }
        return pq.top();
    }
};
```
