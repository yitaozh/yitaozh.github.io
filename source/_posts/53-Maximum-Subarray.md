---
title: 53. Maximum Subarray
categories: Leetcode
date: 2024-07-16 00:26:56
tags:
    - Array
    - Divide and Conquer
    - Dynamic Programming
---

[53. Maximum Subarray](https://leetcode.com/problems/maximum-subarray/description/)

## Description

Given an integer array `nums`, find the subarray with the largest sum, and return its sum.

**Example 1:**

```bash
Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
Output: 6
Explanation: The subarray [4,-1,2,1] has the largest sum 6.
```

**Example 2:**

```bash
Input: nums = [1]
Output: 1
Explanation: The subarray [1] has the largest sum 1.
```

**Example 3:**

```bash
Input: nums = [5,4,-1,7,8]
Output: 23
Explanation: The subarray [5,4,-1,7,8] has the largest sum 23.
```

**Constraints:**

- `1 <= nums.length <= 10^5`
- `-10^4 <= nums[i] <= 10^4`

**Follow up:**  If you have figured out the `O(n)` solution, try coding another solution using the **divide and conquer**  approach, which is more subtle.

## Hints/Notes

- N/A

## Solution

Language: **C++**

```C++
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res = INT_MIN, left = 0, right = 0, cur = 0;
        while (right < nums.size()) {
            cur += nums[right++];
            res = max(res, cur);
            while (cur < 0) {
                cur -= nums[left++];
            }
        }
        return res;
    }
};
```
