---
title: 3151. Special Array I
categories: Leetcode
date: 2024-05-23 11:37:37
tags:
    - Array
---

[3151. Special Array I](https://leetcode.com/problems/special-array-i/description/)

## Description

An array is considered **special**  if every pair of its adjacent elements contains two numbers with different parity.

You are given an array of integers `nums`. Return `true` if `nums` is a **special**  array, otherwise, return `false`.

**Example 1:**

```bash
Input: nums = [1]

Output: true

Explanation:

There is only one element. So the answer is `true`.
```

**Example 2:**

```bash
Input: nums = [2,1,4]

Output: true

Explanation:

There is only two pairs: `(2,1)` and `(1,4)`, and both of them contain numbers with different parity. So the answer is `true`.
```

**Example 3:**

```bash
Input: nums = [4,3,1,6]

Output: false

Explanation:

`nums[1]` and `nums[2]` are both odd. So the answer is `false`.
```

**Constraints:**

- `1 <= nums.length <= 100`
- `1 <= nums[i] <= 100`

## Hints/Notes

- Weekly contest 398

## Solution

Language: **C++**

```C++
class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        bool isSpecial = true;
        for (int i = 0; i < nums.size() - 1; i++) {
            if (!((nums[i] % 2) ^ (nums[i + 1] % 2))) {
                isSpecial = false;
                break;
            }
        }
        return isSpecial;
    }
};
```
