---
title: 852. Peak Index in a Mountain Array
categories: Leetcode
date: 2023-12-02 16:35:47
tags:
    - Array
    - Binary Search
---

# [852\. Peak Index in a Mountain Array](https://leetcode.com/problems/peak-index-in-a-mountain-array/)

## Description

Difficulty: **Medium**

Related Topics: [Array](https://leetcode.com/tag/https://leetcode.com/tag/array//), [Binary Search](https://leetcode.com/tag/https://leetcode.com/tag/binary-search//)

An array `arr` is a **mountain** if the following properties hold:

* `arr.length >= 3`
* There exists some `i` with `0 < i < arr.length - 1` such that:
  * `arr[0] < arr[1] < ... < arr[i - 1] < arr[i]`
  * `arr[i] > arr[i + 1] > ... > arr[arr.length - 1]`

Given a mountain array `arr`, return the index `i` such that `arr[0] < arr[1] < ... < arr[i - 1] < arr[i] > arr[i + 1] > ... > arr[arr.length - 1]`.

You must solve it in `O(log(arr.length))` time complexity.

**Example 1:**

```bash
Input: arr = [0,1,0]
Output: 1
```

**Example 2:**

```bash
Input: arr = [0,2,1,0]
Output: 1
```

**Example 3:**

```bash
Input: arr = [0,10,5,2]
Output: 1
```

**Constraints:**

* 3 <= arr.length <= 10<sup>5</sup>
* 0 <= arr[i] <= 10<sup>6</sup>
* `arr` is **guaranteed** to be a mountain array.

## Hints/Notes

* Variant binary search

## Solution

Language: **C++**

```C++
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int left = 0, right = arr.size() - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (arr[mid] > arr[mid + 1]) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
};
```
