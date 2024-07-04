---
title: 3201. Find the Maximum Length of Valid Subsequence I
categories: Leetcode
date: 2024-07-03 23:40:20
tags:
    - Array
    - Dynamic Programming
---

[3201. Find the Maximum Length of Valid Subsequence I](https://leetcode.com/problems/find-the-maximum-length-of-valid-subsequence-i/description/)

## Description

You are given an integer array `nums`.

A subsequence `sub` of `nums` with length `x` is called **valid**  if it satisfies:

- `(sub[0] + sub[1]) % 2 == (sub[1] + sub[2]) % 2 == ... == (sub[x - 2] + sub[x - 1]) % 2.`

Return the length of the **longest** **valid** subsequence of `nums`.

A **subsequence** is an array that can be derived from another array by deleting some or no elements without changing the order of the remaining elements.

**Example 1:**

```bash
Input: nums = [1,2,3,4]

Output: 4

Explanation:

The longest valid subsequence is `[1, 2, 3, 4]`.
```

**Example 2:**

```bash
Input: nums = [1,2,1,1,2,1,2]

Output: 6

Explanation:

The longest valid subsequence is `[1, 2, 1, 2, 1, 2]`.
```

**Example 3:**

```bash
Input: nums = [1,3]

Output: 2

Explanation:

The longest valid subsequence is `[1, 3]`.
```

**Constraints:**

- `2 <= nums.length <= 2 * 10^5`
- `1 <= nums[i] <= 10^7`

## Hints/Notes

- Weekly Contest 404

## Solution

Language: **C++**

```C++
class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int alleven = 0, evenFirst = 0, allodd = 0, oddFirst = 0;
        bool record1 = true, record2 = false;
        for (int num : nums) {
            if (num % 2 == 0) {
                alleven++;
                if (record1) {
                    evenFirst++;
                    record1 = false;
                }
                if (record2) {
                    oddFirst++;
                    record2 = false;
                }
            } else {
                allodd++;
                if (!record1) {
                    evenFirst++;
                    record1 = true;
                }
                if (!record2) {
                    oddFirst++;
                    record2 = true;
                }
            }
        }
        return max(alleven, max(allodd, max(evenFirst, oddFirst)));
    }
};
```
