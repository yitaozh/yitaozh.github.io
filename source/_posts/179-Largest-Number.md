---
title: 179. Largest Number
categories: Leetcode
date: 2025-02-02 23:42:40
tags:
    - Array
    - String
    - Greedy
    - Sorting
---

[179. Largest Number](https://leetcode.com/problems/largest-number/description/?envType=company&envId=facebook&favoriteSlug=facebook-three-months)

## Description

Given a list of non-negative integers `nums`, arrange them such that they form the largest number and return it.

Since the result may be very large, so you need to return a string instead of an integer.

**Example 1:**

```bash
Input: nums = [10,2]
Output: "210"
```

**Example 2:**

```bash
Input: nums = [3,30,34,5,9]
Output: "9534330"
```

**Constraints:**

- `1 <= nums.length <= 100`
- `0 <= nums[i] <= 10^9`

## Hints/Notes

- 2025/02/01
- string
- [Good solution](https://leetcode.cn/problems/largest-number/solutions/716725/gong-shui-san-xie-noxiang-xin-ke-xue-xi-vn86e/?envType=company&envId=facebook&favoriteSlug=facebook-three-months)

## Solution

Language: **C++**

```C++
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        auto cmp = [](const int l, const int r) {
            string lhs = to_string(l), rhs = to_string(r);
            return lhs + rhs > rhs + lhs;
        };
        sort(nums.begin(), nums.end(), cmp);
        if (nums[0] == 0) {
            return "0";
        }
        string res;
        for (int i = 0; i < nums.size(); i++) {
            res += to_string(nums[i]);
        }
        return res;
    }
};
```
