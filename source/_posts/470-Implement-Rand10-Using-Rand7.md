---
title: 470. Implement Rand10() Using Rand7()
categories: Leetcode
date: 2025-03-18 00:56:38
tags:
    - Math
    - Rejection Sampling
    - Randomized
    - Probability and Statistics
---

[470. Implement Rand10() Using Rand7()](https://leetcode.com/problems/implement-rand10-using-rand7/description/?envType=company&envId=linkedin&favoriteSlug=linkedin-six-months)

## Description

Given the **API**  `rand7()` that generates a uniform random integer in the range `[1, 7]`, write a function `rand10()` that generates a uniform random integer in the range `[1, 10]`. You can only call the API `rand7()`, and you shouldn't call any other API. Please **do not**  use a language's built-in random API.

Each test case will have one **internal**  argument `n`, the number of times that your implemented function `rand10()` will be called while testing. Note that this is **not an argument**  passed to `rand10()`.

**Example 1:**

```bash
Input: n = 1
Output: [2]
```

**Example 2:**

```bash
Input: n = 2
Output: [2,8]
```

**Example 3:**

```bash
Input: n = 3
Output: [3,8,10]
```

**Constraints:**

- `1 <= n <= 10^5`

**Follow up:**

- What is the <a href="https://en.wikipedia.org/wiki/Expected_value" target="_blank">expected value</a> for the number of calls to `rand7()` function?
- Could you minimize the number of calls to `rand7()`?

## Hints/Notes

- 2025/02/16 Q3
- math
- [Leetcode solution](https://leetcode.com/problems/implement-rand10-using-rand7/editorial/?envType=company&envId=linkedin&favoriteSlug=linkedin-six-months)

## Solution

Language: **C++**

```C++
// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7

class Solution {
public:
    int rand10() {
        int row, col, idx;
        do {
            row = rand7();
            col = rand7();
            idx = col + (row - 1) * 7;
        } while (idx > 40);
        return 1 + (idx - 1) % 10;
    }
};
```
