---
title: 4. Median of Two Sorted Arrays
categories: Leetcode
date: 2024-12-16 14:33:52
tags:
    - Array
    - Binary Search
    - Divide and Conquer
---

[4. Median of Two Sorted Arrays](https://leetcode.com/problems/median-of-two-sorted-arrays/description/?envType=problem-list-v2&envId=plakya4j&)

## Description

Given two sorted arrays `nums1` and `nums2` of size `m` and `n` respectively, return **the median**  of the two sorted arrays.

The overall run time complexity should be `O(log (m+n))`.

**Example 1:**

```bash
Input: nums1 = [1,3], nums2 = [2]
Output: 2.00000
Explanation: merged array = [1,2,3] and median is 2.
```

**Example 2:**

```bash
Input: nums1 = [1,2], nums2 = [3,4]
Output: 2.50000
Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.
```

**Constraints:**

- `nums1.length == m`
- `nums2.length == n`
- `0 <= m <= 1000`
- `0 <= n <= 1000`
- `1 <= m + n <= 2000`
- `-10^6 <= nums1[i], nums2[i] <= 10^6`

## Hints/Notes

- 2024/12/15
- binary search
- [0x3F's solution](https://leetcode.cn/problems/median-of-two-sorted-arrays/solutions/2950686/tu-jie-xun-xu-jian-jin-cong-shuang-zhi-z-p2gd/)(checked)

## Solution

Language: **C++**

Self written binary search:

```C++
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) {
            swap(nums1, nums2);
        }
        nums1.insert(nums1.begin(), INT_MIN);
        nums2.insert(nums2.begin(), INT_MIN);
        nums1.push_back(INT_MAX);
        nums2.push_back(INT_MAX);
        int m = nums1.size(), n = nums2.size();
        // the ultimate goal is to have 2 sets of numbers, with the numbers
        // in first set less than the numbers in the second set
        // if we pick l numbers from nums1, then we need to pick (m + n) / 2 - l numbers from nums2
        // nums1[l] is in first set, and nums[r] is in second set
        int l = 0, r = m - 1;
        while (l + 1 < r) {
            int idx1 = (l + r) / 2;
            // it means we would pick [0, mid] elements from nums1
            // then we need (m + n) / 2 - mid - 2 from nums2
            int idx2 = (m + n) / 2 - idx1 - 2;
            // for nums1 index >= r, they belong to the second set
            if (nums1[idx1] > nums2[idx2 + 1]) {
                r = idx1;
            } else {
                l = idx1;
            }
        }
        int idx1 = l, idx2 = (m + n) / 2 - l - 2;
        return (m + n) % 2 ? min(nums1[idx1 + 1], nums2[idx2 + 1]) :
                            (max(nums1[idx1], nums2[idx2]) + min(nums1[idx1 + 1], nums2[idx2 + 1])) / 2.0;
    }
};
```

Self written linear solution:

```C++
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() < nums2.size()) {
            swap(nums1, nums2);
        }
        nums1.insert(nums1.begin(), INT_MIN);
        nums2.insert(nums2.begin(), INT_MIN);
        nums1.push_back(INT_MAX);
        nums2.push_back(INT_MAX);
        int m = nums1.size(), n = nums2.size();
        // MIN, 2, 4, 5, MAX
        // MIN, 1, 3, 6, MAX
        // the ultimate goal is to have 2 sets of numbers, with the numbers
        // in first set less than the numbers in the second set
        // if we pick l numbers from nums1, then we need to pick (m + n) / 2 - l numbers from nums2
        // first, let's assume all numbers are from nums1
        int idx1 = (m + n) / 2 - 2, idx2 = 0;
        // idx1 -> 4, idx2 -> MIN
        // idx1 -> 2, idx2 -> 1
        while (nums1[idx1] > nums2[idx2 + 1]) {
            idx1--;
            idx2++;
        }
        // idx1 -> 5, idx2 -> MIN
        // idx1 -> 4, idx2 -> 1
        // idx1 -> 2, idx2 -> 3
        return (m + n) % 2 ? min(nums1[idx1 + 1], nums2[idx2 + 1]) :
                            (max(nums1[idx1], nums2[idx2]) + min(nums1[idx1 + 1], nums2[idx2 + 1])) / 2.0;
    }
};
```

binary search

```C++
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) {
            swap(nums1, nums2);
        }
        int m = nums1.size(), n = nums2.size();
        nums1.insert(nums1.begin(), INT_MIN);
        nums2.insert(nums2.begin(), INT_MIN);
        nums1.push_back(INT_MAX);
        nums2.push_back(INT_MAX);
        int left = 0, right = m + 1;
        while (left + 1 < right) {
            int i = (right - left) / 2 + left;
            int j = (m + n + 1) / 2 - i;
            if (nums1[i] <= nums2[j + 1]) {
                left = i;
            } else {
                right = i;
            }
        }
        int i = left, j = (m + n + 1) / 2 - i;
        int max1 = max(nums1[i], nums2[j]);
        int min2 = min(nums1[i + 1], nums2[j + 1]);
        return (m + n) % 2 ? max1 : (max1 + min2) / 2.0;
    }
};
```

linear result

```C++
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) {
            swap(nums1, nums2);
        }
        int m = nums1.size(), n = nums2.size();
        nums1.insert(nums1.begin(), INT_MIN);
        nums2.insert(nums2.begin(), INT_MIN);
        nums1.push_back(INT_MAX);
        nums2.push_back(INT_MAX);
        int i = 0, j = (m + n + 1) / 2;
        while (true) {
            if (nums1[i] <= nums2[j + 1] && nums1[i + 1] >= nums2[j]) {
                int max1 = max(nums1[i], nums2[j]);
                int min2 = min(nums1[i + 1], nums2[j + 1]);
                return (m + n) % 2 ? max1 : (max1 + min2) / 2.0;
            }
            i++;
            j--;
        }
    }
};
```
