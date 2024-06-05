---
title: 3171. Find Subarray With Bitwise AND Closest to K
categories: Leetcode
date: 2024-06-05 01:31:13
tags:
    - Array
    - Binary Search
    - Bit Manipulation
    - Segment Tree
---

[3171. Find Subarray With Bitwise AND Closest to K](https://leetcode.com/problems/find-subarray-with-bitwise-and-closest-to-k/description/)

## Description

You are given an array `nums` and an integer `k`. You need to find a subarray of `nums` such that the **absolute difference**  between `k` and the bitwise `AND` of the subarray elements is as **small**  as possible. In other words, select a subarray `nums[l..r]` such that `|k - (nums[l] AND nums[l + 1] ... AND nums[r])|` is minimum.

Return the **minimum**  possible value of the absolute difference.

A **subarray**  is a contiguous <b>non-empty</b> sequence of elements within an array.

**Example 1:**

```bash
Input: nums = [1,2,4,5], k = 3

Output: 1

Explanation:

The subarray `nums[2..3]` has `AND` value 4, which gives the minimum absolute difference `|3 - 4| = 1`.
```

**Example 2:**

```bash
Input: nums = [1,2,1,2], k = 2

Output: 0

Explanation:

The subarray `nums[1..1]` has `AND` value 2, which gives the minimum absolute difference `|2 - 2| = 0`.
```

**Example 3:**

```bash
Input: nums = [1], k = 10

Output: 9

Explanation:

There is a single subarray with `AND` value 1, which gives the minimum absolute difference `|10 - 1| = 9`.
```

**Constraints:**

- `1 <= nums.length <= 10^5`
- `1 <= nums[i] <= 10^9`
- `1 <= k <= 10^9`

## Hints/Notes

- sliding window or bit operation
- Weekly Contest 400

## Solution

Language: **C++**

Bit operation:

```C++
class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        int res = INT_MAX;
        for (int i = 0; i < nums.size(); i++) {
            int x = nums[i];
            res = min(res, abs(x - k));
            for (int j = i - 1; j >= 0; j--) {
                if ((nums[j] & x) == nums[j]) {
                    break;
                }
                nums[j] &= x;
                res = min(res, abs(nums[j] - k));
            }
        }
        return res;
    }
};
```

Sliding window:

```C++
class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        int left = 0, right = 0, cur = INT_MAX, res = INT_MAX;
        while (right < nums.size()) {
            cur &= nums[right];
            res = min(res, abs(k - cur));
            if (cur == k) {
                return 0;
            } else if (cur < k) {
                int tmp = INT_MAX, j = right;
                for ( ; j >= left; j--) {
                    if ((tmp & nums[j]) == k) {
                        return 0;
                    } else if ((tmp & nums[j]) < k) {
                        res = min(res, abs(k - (tmp & nums[j])));
                        cur = tmp;
                        break;
                    }
                    tmp &= nums[j];
                    res = min(res, abs(k - tmp));
                }
                left = j;
            }
            right++;
        }
        return res;
    }
};
```
