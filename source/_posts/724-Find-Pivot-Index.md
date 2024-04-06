---
title: 724. Find Pivot Index
categories: Leetcode
date: 2023-11-12 23:04:44
tags:
    - Array
    - Prefix Sum
---

[724\. Find Pivot Index](https://leetcode.com/problems/find-pivot-index/)

## Description

Difficulty: **Easy**

Related Topics: [Array](https://leetcode.com/tag/https://leetcode.com/tag/array//), [Prefix Sum](https://leetcode.com/tag/https://leetcode.com/tag/prefix-sum//)

Given an array of integers `nums`, calculate the **pivot index** of this array.

The **pivot index** is the index where the sum of all the numbers **strictly** to the left of the index is equal to the sum of all the numbers **strictly** to the index's right.

If the index is on the left edge of the array, then the left sum is `0` because there are no elements to the left. This also applies to the right edge of the array.

Return _the **leftmost pivot index**_. If no such index exists, return `-1`.

**Example 1:**

```bash
Input: nums = [1,7,3,6,5,6]
Output: 3
Explanation:
The pivot index is 3.
Left sum = nums[0] + nums[1] + nums[2] = 1 + 7 + 3 = 11
Right sum = nums[4] + nums[5] = 5 + 6 = 11
```

**Example 2:**

```bash
Input: nums = [1,2,3]
Output: -1
Explanation:
There is no index that satisfies the conditions in the problem statement.
```

**Example 3:**

```bash
Input: nums = [2,1,-1]
Output: 0
Explanation:
The pivot index is 0.
Left sum = 0 (no elements to the left of index 0)
Right sum = nums[1] + nums[2] = 1 + -1 = 0
```

**Constraints:**

* 1 <= nums.length <= 10<sup>4</sup>
* `-1000 <= nums[i] <= 1000`

**Note:** This question is the same as 1991: [https://leetcode.com/problems/find-the-middle-index-in-array/](https://leetcode.com/problems/find-the-middle-index-in-array/)

## Hints/Notes

* preSum

## Solution

Language: **C++**

```C++
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int size = nums.size();
        vector<int> preSum(size + 1, 0);
        for (int i = 0; i < size; i++) {
            preSum[i + 1] = preSum[i] + nums[i];
        }
        for (int i = 0; i < size; i++) {
            if (preSum[i] == preSum[size] - preSum[i + 1]) {
                return i;
            }
        }
        return -1;
    }
};
```
