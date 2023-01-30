---
title: 1137. N-th Tribonacci Number
categories: Leetcode
date: 2023-01-30 13:13:58
tags:
    - Math
    - Dynamic Programming
    - Memoization
---

# [1137\. N-th Tribonacci Number](https://leetcode.com/problems/n-th-tribonacci-number/)

## Description

Difficulty: **Easy**

Related Topics: [Math](https://leetcode.com/tag/math/), [Dynamic Programming](https://leetcode.com/tag/dynamic-programming/), [Memoization](https://leetcode.com/tag/memoization/)

The Tribonacci sequence T<sub>n</sub> is defined as follows:

T<sub>0</sub> = 0, T<sub>1</sub> = 1, T<sub>2</sub> = 1, and T<sub>n+3</sub> = T<sub>n</sub> + T<sub>n+1</sub> + T<sub>n+2</sub> for n >= 0.

Given `n, return the value of T<sub>n</sub>.

**Example 1:**

```text
Input: n = 4
Output: 4
Explanation:
T_3 = 0 + 1 + 1 = 2
T_4 = 1 + 1 + 2 = 4
```

**Example 2:**

```text
Input: n = 25
Output: 1389537
```

**Constraints:**

* `0 <= n <= 37`
* The answer is guaranteed to fit within a 32-bit integer, ie. `answer <= 2^31 - 1`.

## Solution

Language: **C++**

```C++
class Solution {
public:
    int tribonacci(int n) {
        if (n == 0) return 0;
        if (n == 1 || n == 2) return 1;
        vector<int> res = {0, 1, 1};
        int i = 3;
        while (i <= n) {
            res.push_back(res[i - 3] + res[i - 2] + res[i - 1]);
            i++;
        }
        return res[n];
    }
};
```
