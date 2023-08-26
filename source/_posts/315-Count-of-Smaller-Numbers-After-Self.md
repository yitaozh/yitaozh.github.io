---
title: 315. Count of Smaller Numbers After Self
categories: Leetcode
date: 2023-08-24 23:38:04
tags:
---
# [315\. Count of Smaller Numbers After Self](https://leetcode.com/problems/count-of-smaller-numbers-after-self/)

## Description

Difficulty: **Hard**

Related Topics: [Array](https://leetcode.com/tag/https://leetcode.com/tag/array//), [Binary Search](https://leetcode.com/tag/https://leetcode.com/tag/binary-search//), [Divide and Conquer](https://leetcode.com/tag/https://leetcode.com/tag/divide-and-conquer//), [Binary Indexed Tree](https://leetcode.com/tag/https://leetcode.com/tag/binary-indexed-tree//), [Segment Tree](https://leetcode.com/tag/https://leetcode.com/tag/segment-tree//), [Merge Sort](https://leetcode.com/tag/https://leetcode.com/tag/merge-sort//), [Ordered Set](https://leetcode.com/tag/https://leetcode.com/tag/ordered-set//)

Given an integer array `nums`, return _an integer array_ `counts` _where_ `counts[i]` _is the number of smaller elements to the right of_ `nums[i]`.

**Example 1:**

```bash
Input: nums = [5,2,6,1]
Output: [2,1,1,0]
Explanation:
To the right of 5 there are 2 smaller elements (2 and 1).
To the right of 2 there is only 1 smaller element (1).
To the right of 6 there is 1 smaller element (1).
To the right of 1 there is 0 smaller element.
```

**Example 2:**

```bash
Input: nums = [-1]
Output: [0]
```

**Example 3:**

```bash
Input: nums = [-1,-1]
Output: [0,0]
```

**Constraints:**

* 1 <= nums.length <= 10<sup>5</sup>
* -10<sup>4</sup> <= nums[i] <= 10<sup>4</sup>

## Hints/Notes

* Merge sort
* Compare tmp array with doing the merge

## Solution

Language: **C++**

```C++
class Solution {
public:
    vector<int> res;
    vector<pair<int, int>> tmp;

    vector<int> countSmaller(vector<int>& nums) {
       vector<pair<int, int>> arr;
       int size = nums.size();
       for (int i = 0; i < size; i++) {
           arr.push_back({nums[i], i});
       }
       res = vector<int>(size, 0);
       tmp = vector<pair<int, int>>(size, {0, 0});
       sort(arr, 0, nums.size() - 1);
       return res;
    }

    void sort(vector<pair<int, int>>& arr, int low, int high) {
        if (low >= high) {
            return;
        }
        int mid = low + (high - low) / 2;
        sort(arr, low, mid);
        sort(arr, mid + 1, high);
        merge(arr, low, mid, high);
    }

    void merge(vector<pair<int, int>>& arr, int low, int mid, int high) {
        for (int i = low; i <= high; i++) {
            tmp[i] = arr[i];
        }

        int index = low, p1 = low, p2 = mid + 1;
        while (index <= high) {
            if (p1 == mid + 1) {
                arr[index++] = tmp[p2++];
            } else if (p2 == high + 1) {
                res[tmp[p1].second] += p2 - mid - 1;
                arr[index++] = tmp[p1++];
            } else if (tmp[p1].first > tmp[p2].first) {
                arr[index++] = tmp[p2++];
            } else {
                res[tmp[p1].second] += p2 - mid - 1;
                arr[index++] = tmp[p1++];
            }
        }
    }
};
```
