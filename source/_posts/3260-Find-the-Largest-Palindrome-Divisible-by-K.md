---
title: 3260. Find the Largest Palindrome Divisible by K
categories: Leetcode
date: 2024-10-03 23:55:18
tags:
    - Math
    - String
    - Dynamic Programming
    - Greedy
    - Number Theory
---

[3260. Find the Largest Palindrome Divisible by K](https://leetcode.com/problems/find-the-largest-palindrome-divisible-by-k/description/)

## Description

You are given two **positive**  integers `n` and `k`.

An integer `x` is called **k-palindromic**  if:

- `x` is a palindrome.
- `x` is divisible by `k`.

Return the **largest** integer having `n` digits (as a string) that is **k-palindromic** .

**Note**  that the integer must **not**  have leading zeros.

**Example 1:**

```bash
Input: n = 3, k = 5

Output: "595"
```

Explanation:

595 is the largest k-palindromic integer with 3 digits.

**Example 2:**

```bash
Input: n = 1, k = 4

Output: "8"
```

Explanation:

4 and 8 are the only k-palindromic integers with 1 digit.

**Example 3:**

```bash
Input: n = 5, k = 6

Output: "89898"
```

**Constraints:**

- `1 <= n <= 10^5`
- `1 <= k <= 9`

## Hints/Notes

- 2024/08/20
- dp
- [0x3F's solution](https://leetcode.cn/problems/find-the-largest-palindrome-divisible-by-k/solutions/2884548/tong-yong-zuo-fa-jian-tu-dfsshu-chu-ju-t-m3pu/)(checked)
- Weekly Contest 411

## Solution

Language: **C++**

```C++
class Solution {
public:
    // the meaning of dp[i][j]: when we are handling the ith digit
    // (also n - 1 - i), with remainder = j, can we form the number successfully
    // why we can use this dp state? because only the digit and reminder matter, not what we have filled in
    vector<vector<int>> dp;
    vector<int> div;
    int n_, k_, h_;
    string res;
    string largestPalindrome(int n, int k) {
        h_ = (n + 1) / 2;
        n_ = n;
        k_ = k;
        dp.resize(h_, vector<int>(k, -1));
        div.resize(n, 1);
        res = string(n, '0');
        for (int i = 1; i < n; i++) {
            div[i] = div[i - 1] * 10 % k;
        }
        dfs(0, 0);
        return res;
    }

    bool dfs(int i, int j) {
        if (i >= h_) {
            return j == 0;
        }
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        bool ans = false;
        for (int k = 9; k >= 0; k--) {
            int j2 = j;
            if (n_ % 2 && i == h_ - 1) {
                j2 = (j2 + k * div[i]) % k_;
            } else {
                j2 = (j2 + k * div[i] + k * div[n_ - 1 - i]) % k_;
            }
            if (dfs(i + 1, j2)) {
                res[i] = k + '0';
                res[n_ - 1 - i] = k + '0';
                ans = true;
                break;
            }
        }
        dp[i][j] = ans;
        return ans;
    }
};
```
