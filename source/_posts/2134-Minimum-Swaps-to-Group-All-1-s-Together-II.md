---
title: 2134. Minimum Swaps to Group All 1's Together II
categories: Leetcode
date: 2024-10-25 21:33:11
tags:
    - Array
    - Sliding Window
---

[2134. Minimum Swaps to Group All 1's Together II](https://leetcode.com/problems/minimum-swaps-to-group-all-1s-together-ii/description/)

## Description

A **swap**  is defined as taking two **distinct**  positions in an array and swapping the values in them.

A **circular**  array is defined as an array where we consider the **first**  element and the **last**  element to be **adjacent** .

Given a **binary**  **circular**  array `nums`, return the minimum number of swaps required to group all `1`'s present in the array together at **any location** .

**Example 1:**

```bash
Input: nums = [0,1,0,1,1,0,0]
Output: 1
Explanation: Here are a few of the ways to group all the 1's together:
[0,0,1,1,1,0,0] using 1 swap.
[0,1,1,1,0,0,0] using 1 swap.
[1,1,0,0,0,0,1] using 2 swaps (using the circular property of the array).
There is no way to group all 1's together with 0 swaps.
Thus, the minimum number of swaps required is 1.
```

**Example 2:**

```bash
Input: nums = [0,1,1,1,0,0,1,1,0]
Output: 2
Explanation: Here are a few of the ways to group all the 1's together:
[1,1,1,0,0,0,0,1,1] using 2 swaps (using the circular property of the array).
[1,1,1,1,1,0,0,0,0] using 2 swaps.
There is no way to group all 1's together with 0 or 1 swaps.
Thus, the minimum number of swaps required is 2.
```

**Example 3:**

```bash
Input: nums = [1,1,0,0,1]
Output: 0
Explanation: All the 1's are already grouped together due to the circular property of the array.
Thus, the minimum number of swaps required is 0.
```

**Constraints:**

- `1 <= nums.length <= 10^5`
- `nums[i]` is either `0` or `1`.

## Hints/Notes

- sliding window
- No solution from 0x3F

## Solution

Language: **C++**

```C++
class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size(), right = 0, k = 0, mx = 0, cur = 0;
        for (int d : nums) {
            k += d;
        }
        while (right < n + k) {
            int r = nums[right % n];
            cur += r;
            if (right >= k - 1) {
                mx = max(mx, cur);
                cur -= nums[(right - k + 1) % n];
            }
            right++;
        }
        return k - mx;
    }
};
```
