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

* Priority queue
* Quick sort

## Solution

Language: **C++**

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

The quick sort solution(cannot pass the last test case)

```C++
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        shuffle(nums);
        k = nums.size() - k;
        int low = 0, high = nums.size() - 1;
        while (low <= high) {
            int p = partition(nums, low, high);
            if (p == k) {
                return nums[p];
            } else if (p > k) {
                high = p - 1;
            } else {
                low = p + 1;
            }
        }
        return -1;
    }

    int partition(vector<int>& nums, int low, int high) {
        int pivot = nums[low];
        int i = low + 1, j = high;
        while (i <= j) {
            while (i < high && nums[i] <= pivot) i++;
            while (low < j && nums[j] > pivot) j--;
            if (i >= j) break;
            swap(nums, i, j);
        }
        swap(nums, low, j);
        // cout << "value of pivot: " << pivot << " index: " << j << " low: " << low << " high: " << high << endl;
        // for (int num: nums) cout << num; cout << endl;
        return j;
    }

    void swap(vector<int>& nums, int i, int j) {
        int tmp = nums[i];
        nums[i] = nums[j];
        nums[j] = tmp;
    }

    void shuffle(vector<int>& nums) {
        int size = nums.size();
        for (int i = 0; i < size; i++) {
            int rand = i + std::rand() % (size - i);
            swap(nums, i, rand);
        }
    }
};
```
