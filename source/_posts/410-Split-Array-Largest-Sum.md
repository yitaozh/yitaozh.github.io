---
title: 410. Split Array Largest Sum
categories: Leetcode
date: 2023-01-30 12:30:36
tags:
    - Array
    - Binary Search
    - Dynamic Programming
    - Greedy
---

[410\. Split Array Largest Sum](https://leetcode.com/problems/split-array-largest-sum/)

## Description

Difficulty: **Hard**

Related Topics: [Array](https://leetcode.com/tag/array/), [Binary Search](https://leetcode.com/tag/binary-search/), [Dynamic Programming](https://leetcode.com/tag/dynamic-programming/), [Greedy](https://leetcode.com/tag/greedy/)

Given an integer array `nums` and an integer `k`, split `nums` into `k` non-empty subarrays such that the largest sum of any subarray is **minimized**.

Return _the minimized largest sum of the split_.

A **subarray** is a contiguous part of the array.

**Example 1:**

```text
Input: nums = [7,2,5,10,8], k = 2
Output: 18
Explanation: There are four ways to split nums into two subarrays.
The best way is to split it into [7,2,5] and [10,8], where the largest sum among the two subarrays is only 18.
```

**Example 2:**

```text
Input: nums = [1,2,3,4,5], k = 2
Output: 9
Explanation: There are four ways to split nums into two subarrays.
The best way is to split it into [1,2,3] and [4,5], where the largest sum among the two subarrays is only 9.
```

**Constraints:**

* `1 <= nums.length <= 1000`
* 0 <= nums[i] <= 10<sup>6</sup>
* `1 <= k <= min(50, nums.length)`

## Hints/Notes

* Read the problem: A subarray is a **contiguous** part of the array.
* Use binary search and helper function to find the left boundary

## Solution

Language: **C++**

```C++
class Solution {
public:
    int subarrayNum(vector<int>& nums, int s) {
        int num = 0;
        for (int i = 0; i < nums.size();) {
            int sum = 0;
            while (sum <= s && i < nums.size()) {
                sum += nums[i++];
            }
            if (sum > s) {
                i--;
            }
            num++;
        }
        return num;
    }

    int splitArray(vector<int>& nums, int k) {
        int left = 0, right = 0;
        for (int num : nums) {
            if (num > left) {
                left = num;
            }
            right += num;
        }
        while (left <= right) {
            int mid = left + (right - left) / 2;
            int subNum = subarrayNum(nums, mid);
            if (subNum == k) {
                right = mid - 1;
            } else if (subNum > k) {
                left = mid + 1;
            } else if (subNum < k) {
                right = mid - 1;
            }
        }
        return left;
    }
};
```
