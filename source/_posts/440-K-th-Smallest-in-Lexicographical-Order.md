---
title: 440. K-th Smallest in Lexicographical Order
categories: Leetcode
date: 2025-04-27 17:38:08
tags:
    - Trie
---

[440. K-th Smallest in Lexicographical Order](https://leetcode.com/problems/k-th-smallest-in-lexicographical-order/description/?envType=company&envId=tiktok&favoriteSlug=tiktok-six-months)

## Description

Given two integers `n` and `k`, return the `k^th` lexicographically smallest integer in the range `[1, n]`.

**Example 1:**

```bash
Input: n = 13, k = 2
Output: 10
Explanation: The lexicographical order is [1, 10, 11, 12, 13, 2, 3, 4, 5, 6, 7, 8, 9], so the second smallest number is 10.
```

**Example 2:**

```bash
Input: n = 1, k = 1
Output: 1
```

**Constraints:**

- `1 <= k <= n <= 10^9`

## Hints/Notes

- 2025/04/24 Q2
- Trie
- [Leetcode solution](https://leetcode.com/problems/k-th-smallest-in-lexicographical-order/editorial/)

## Solution

Language: **C++**

```C++
class Solution {
public:
    int findKthNumber(int n, int k) {
        int cur = 1;
        k--;

        while (k > 0) {
            int step = countSteps(n, cur, cur + 1);
            if (step <= k) {
                cur++;
                k -= step;
            } else {
                cur *= 10;
                k--;
            }
        }
        return cur;
    }

    int countSteps(int n, long prefix1, long prefix2) {
        int steps = 0;
        while (prefix1 <= n) {
            steps += min((long)(n + 1), prefix2) - prefix1;
            prefix1 *= 10;
            prefix2 *= 10;
        }
        return steps;
    }
};
```
