---
title: 509. Fibonacci Number
categories: Leetcode
date: 2023-11-08 23:34:48
tags:
    - Math
    - Dynamic Programming
    - Recursion
    - Memoization
---

[509\. Fibonacci Number](https://leetcode.com/problems/fibonacci-number/)

## Description

Difficulty: **Easy**

Related Topics: [Math](https://leetcode.com/tag/https://leetcode.com/tag/math//), [Dynamic Programming](https://leetcode.com/tag/https://leetcode.com/tag/dynamic-programming//), [Recursion](https://leetcode.com/tag/https://leetcode.com/tag/recursion//), [Memoization](https://leetcode.com/tag/https://leetcode.com/tag/memoization//)

The **Fibonacci numbers**, commonly denoted `F(n)` form a sequence, called the **Fibonacci sequence**, such that each number is the sum of the two preceding ones, starting from `0` and `1`. That is,

```bash
F(0) = 0, F(1) = 1
F(n) = F(n - 1) + F(n - 2), for n > 1.
```

Given `n`, calculate `F(n)`.

**Example 1:**

```bash
Input: n = 2
Output: 1
Explanation: F(2) = F(1) + F(0) = 1 + 0 = 1.
```

**Example 2:**

```bash
Input: n = 3
Output: 2
Explanation: F(3) = F(2) + F(1) = 1 + 1 = 2.
```

**Example 3:**

```bash
Input: n = 4
Output: 3
Explanation: F(4) = F(3) + F(2) = 2 + 1 = 3.
```

**Constraints:**

* `0 <= n <= 30`

## Hints/Notes

* simplest dp

## Solution

Language: **C++**

```C++
class Solution {
public:
    int fib(int n) {
        if (n == 0 || n == 1) {
            return n;
        }
        vector<int> nums{0, 1};
        for (int i = 2; i <= n; i++) {
            nums.push_back(nums[i - 1] + nums[i - 2]);
        }
        return nums[n];
    }
};
```
