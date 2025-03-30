---
title: 1814. Count Nice Pairs in an Array
categories: Leetcode
date: 2025-03-28 00:37:09
tags:
    - Array
    - Hash Table
    - Math
    - Counting
---

[1814. Count Nice Pairs in an Array](https://leetcode.com/problems/count-nice-pairs-in-an-array/description/)

## Description

You are given an array `nums` that consists of non-negative integers. Let us define `rev(x)` as the reverse of the non-negative integer `x`. For example, `rev(123) = 321`, and `rev(120) = 21`. A pair of indices `(i, j)` is **nice**  if it satisfies all of the following conditions:

- `0 <= i < j < nums.length`
- `nums[i] + rev(nums[j]) == nums[j] + rev(nums[i])`

Return the number of nice pairs of indices. Since that number can be too large, return it **modulo**  `10^9 + 7`.

**Example 1:**

```bash
Input: nums = [42,11,1,97]
Output: 2
Explanation: The two pairs are:
 - (0,3) : 42 + rev(97) = 42 + 79 = 121, 97 + rev(42) = 97 + 24 = 121.
 - (1,2) : 11 + rev(1) = 11 + 1 = 12, 1 + rev(11) = 1 + 11 = 12.
```

**Example 2:**

```bash
Input: nums = [13,10,35,24,76]
Output: 4
```

**Constraints:**

- `1 <= nums.length <= 10^5`
- `0 <= nums[i] <= 10^9`

## Hints/Notes

- 2025/03/24 Q1
- counting
- [Leetcode solution](https://leetcode.com/problems/count-nice-pairs-in-an-array/editorial/)

## Solution

Language: **C++**

```C++
class Solution {
public:
    const int MOD = 1e9 + 7;

    int countNicePairs(vector<int>& nums) {
        unordered_map<int, int> count;
        long res = 0;
        for (int num : nums) {
            string numStr = to_string(num);
            reverse(numStr.begin(), numStr.end());
            int val = num - stoi(numStr);
            res = (res + count[val]) % MOD;
            count[val]++;
        }
        return res;
    }
};
```
