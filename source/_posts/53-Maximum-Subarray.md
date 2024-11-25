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

- sliding window
- segment tree

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

Segment tree:

```C++
class Solution {
public:
    vector<array<int, 4>> t;

    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        t.resize(2 << (32 - __builtin_clz(n)));
        build(nums, 1, 0, n - 1);
        int res = t[1][0];
        return res;
    }

    void build(vector<int>& nums, int o, int l, int r) {
        if (l == r) {
            t[o][0] = t[o][1] = t[o][2] = t[o][3] = nums[l];
            return;
        }
        int m = (l + r) / 2;
        build(nums, o * 2, l, m);
        build(nums, o * 2 + 1, m + 1, r);
        maintain(nums, o, l, r);
    }

    void maintain(vector<int>& nums, int o, int l, int r) {
        auto &o1 = t[o * 2], &o2 = t[o * 2 + 1];
        t[o][0] = max(o1[1] + o2[2], max(o1[0], o2[0]));
        t[o][1] = max(o1[1] + o2[3], o2[1]);
        t[o][2] = max(o1[3] + o2[2], o1[2]);
        t[o][3] = o1[3] + o2[3];
    }
};
```
