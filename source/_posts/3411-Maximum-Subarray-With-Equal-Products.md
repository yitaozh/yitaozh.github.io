---
title: 3411. Maximum Subarray With Equal Products
categories: Leetcode
date: 2025-01-10 17:50:30
tags:
    - Array
    - Math
    - Sliding Window
    - Enumeration
    - Number Theory
---

[3411. Maximum Subarray With Equal Products](https://leetcode.com/problems/maximum-subarray-with-equal-products/description/)

## Description

You are given an array of **positive**  integers `nums`.

An array `arr` is called **product equivalent**  if `prod(arr) == lcm(arr) * gcd(arr)`, where:

- `prod(arr)` is the product of all elements of `arr`.
- `gcd(arr)` is the GCD of all elements of `arr`.
- `lcm(arr)` is the LCM of all elements of `arr`.

Return the length of the **longest product equivalent** subarray of `nums`.

**Example 1:**

```bash
Input: nums = [1,2,1,2,1,1,1]

Output: 5
```

Explanation:

The longest product equivalent subarray is `[1, 2, 1, 1, 1]`, where`prod([1, 2, 1, 1, 1]) = 2`,`gcd([1, 2, 1, 1, 1]) = 1`, and`lcm([1, 2, 1, 1, 1]) = 2`.

**Example 2:**

```bash
Input: nums = [2,3,4,5,6]

Output: 3
```

Explanation:

The longest product equivalent subarray is `[3, 4, 5].`

**Example 3:**

```bash
Input: nums = [1,2,3,1,4,5,1]

Output: 5
```

**Constraints:**

- `2 <= nums.length <= 100`
- `1 <= nums[i] <= 10`

## Hints/Notes

- 2025/01/12
- [0x3F's solution](https://leetcode.cn/problems/maximum-subarray-with-equal-products/solutions/3039079/mei-ju-ti-qian-tui-chu-xun-huan-pythonja-a21k/)(checked)
- Weekly Contest 431

## Solution

Language: **C++**

```C++
class Solution {
public:
    int maxLength(vector<int>& nums) {
        int res = 0, max_l = 1, max_g = ranges::max(nums);
        for (int num : nums) {
            max_l = lcm(max_l, num);
        }
        for (int i = 0; i < nums.size(); i++) {
            int end = i;
            long l = 1, g = 0, prod = 1;
            while (end < nums.size() && prod <= max_l * max_g) {
                prod *= nums[end];
                l = lcm(l, nums[end]);
                g = gcd(g, nums[end]);
                if (prod == l * g) {
                    res = max(res, end - i + 1);
                }
                end++;
            }
        }
        return res;
    }
};
```
