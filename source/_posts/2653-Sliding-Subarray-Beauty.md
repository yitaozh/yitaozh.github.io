---
title: 2653. Sliding Subarray Beauty
categories: Leetcode
date: 2024-10-25 21:16:34
tags:
    - Array
    - Hash Table
    - Sliding Window
---

[2653. Sliding Subarray Beauty](https://leetcode.com/problems/sliding-subarray-beauty/description/)

## Description

Given an integer array `nums` containing `n` integers, find the **beauty**  of each subarray of size `k`.

The **beauty**  of a subarray is the `x^th` **smallest integer** in the subarray if it is **negative** , or `0` if there are fewer than `x` negative integers.

Return an integer array containing `n - k + 1` integers, which denote the **beauty**  of the subarrays **in order**  from the first index in the array.

- A subarray is a contiguous **non-empty**  sequence of elements within an array.

**Example 1:**

```bash
Input: nums = [1,-1,-3,-2,3], k = 3, x = 2
Output: [-1,-2,-2]
Explanation: There are 3 subarrays with size k = 3.
The first subarray is `[1, -1, -3]` and the 2^nd smallest negative integer is -1.
The second subarray is `[-1, -3, -2]` and the 2^nd smallest negative integer is -2.
The third subarray is `[-3, -2, 3]`and the 2^nd smallest negative integer is -2.
```

**Example 2:**

```bash
Input: nums = [-1,-2,-3,-4,-5], k = 2, x = 2
Output: [-1,-2,-3,-4]
Explanation: There are 4 subarrays with size k = 2.
For `[-1, -2]`, the 2^nd smallest negative integer is -1.
For `[-2, -3]`, the 2^nd smallest negative integer is -2.
For `[-3, -4]`, the 2^nd smallest negative integer is -3.
For `[-4, -5]`, the 2^nd smallest negative integer is -4.
```

**Example 3:**

```bash
Input: nums = [-3,1,2,-3,0,-3], k = 2, x = 1
Output: [-3,0,-3,-3,-3]
Explanation: There are 5 subarrays with size k = 2.
For `[-3, 1]`, the 1^st smallest negative integer is -3.
For `[1, 2]`, there is no negative integer so the beauty is 0.
For `[2, -3]`, the 1^st smallest negative integer is -3.
For `[-3, 0]`, the 1^st smallest negative integer is -3.
For `[0, -3]`, the 1^st smallest negative integer is -3.
```

**Constraints:**

- `n == nums.length`
- `1 <= n <= 10^5`
- `1 <= k <= n`
- `1 <= x <= k`
- `-50<= nums[i] <= 50`

## Hints/Notes

- sliding window with 2 sets

## Solution

Language: **C++**

```C++
class Solution {
public:
    vector<int> getSubarrayBeauty(vector<int>& nums, int k, int x) {
        multiset<int> mx, mi;
        int n = nums.size(), right = 0;
        vector<int> res;
        while (right < n) {
            int num = nums[right];
            mi.insert(num);
            if (mi.size() > x) {
                auto it = prev(mi.end());
                mx.insert(*it);
                mi.erase(it);
            }
            if (right >= k - 1) {
                auto it = prev(mi.end());
                res.push_back(*it < 0 ? *it : 0);
                // we need to remove l from one of the set
                int l = nums[right - k + 1];
                if (mx.contains(l)) {
                    auto it = mx.lower_bound(l);
                    mx.erase(it);
                } else {
                    auto it = mi.lower_bound(l);
                    mi.erase(it);
                    while (!mx.empty() && mi.size() < x) {
                        it = mx.begin();
                        mi.insert(*it);
                        mx.erase(it);
                    }
                }
            }
            right++;
        }
        return res;
    }
};
```
