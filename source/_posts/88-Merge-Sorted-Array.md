---
title: 88. Merge Sorted Array
categories: Leetcode
date: 2023-11-11 23:03:46
tags:
    - Array
    - Two Pointers
    - Sorting
---

# [88\. Merge Sorted Array](https://leetcode.com/problems/merge-sorted-array/)

## Description

Difficulty: **Easy**

Related Topics: [Array](https://leetcode.com/tag/https://leetcode.com/tag/array//), [Two Pointers](https://leetcode.com/tag/https://leetcode.com/tag/two-pointers//), [Sorting](https://leetcode.com/tag/https://leetcode.com/tag/sorting//)

You are given two integer arrays `nums1` and `nums2`, sorted in **non-decreasing order**, and two integers `m` and `n`, representing the number of elements in `nums1` and `nums2` respectively.

**Merge** `nums1` and `nums2` into a single array sorted in **non-decreasing order**.

The final sorted array should not be returned by the function, but instead be _stored inside the array_ `nums1`. To accommodate this, `nums1` has a length of `m + n`, where the first `m` elements denote the elements that should be merged, and the last `n` elements are set to `0` and should be ignored. `nums2` has a length of `n`.

**Example 1:**

```bash
Input: nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
Output: [1,2,2,3,5,6]
Explanation: The arrays we are merging are [1,2,3] and [2,5,6].
The result of the merge is [1,2,2,3,5,6] with the underlined elements coming from nums1.
```

**Example 2:**

```bash
Input: nums1 = [1], m = 1, nums2 = [], n = 0
Output: [1]
Explanation: The arrays we are merging are [1] and [].
The result of the merge is [1].
```

**Example 3:**

```bash
Input: nums1 = [0], m = 0, nums2 = [1], n = 1
Output: [1]
Explanation: The arrays we are merging are [] and [1].
The result of the merge is [1].
Note that because m = 0, there are no elements in nums1\. The 0 is only there to ensure the merge result can fit in nums1.
```

**Constraints:**

* `nums1.length == m + n`
* `nums2.length == n`
* `0 <= m, n <= 200`
* `1 <= m + n <= 200`
* -10<sup>9</sup> <= nums1[i], nums2[j] <= 10<sup>9</sup>

**Follow up:** Can you come up with an algorithm that runs in `O(m + n)` time?

## Hints/Notes

* Two pointers

## Solution

Language: **C++**

```C++
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int idx1 = m - 1, idx2 = n - 1, idx = m + n - 1;
        while (idx1 >= 0 || idx2 >= 0) {
            if (idx1 < 0) {
                nums1[idx--] = nums2[idx2--];
            } else if (idx2 < 0) {
                nums1[idx--] = nums1[idx1--];
            } else if (nums1[idx1] > nums2[idx2]) {
                nums1[idx--] = nums1[idx1--];
            } else {
                nums1[idx--] = nums2[idx2--];
            }
        }
    }
};
```
