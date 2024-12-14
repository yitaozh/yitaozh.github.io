---
title: 3007. Maximum Number That Sum of the Prices Is Less Than or Equal to K
categories: Leetcode
date: 2024-11-30 17:36:25
tags:
    - Binary Search
    - Dynamic Programming
    - Bit Manipulation
---

[3007. Maximum Number That Sum of the Prices Is Less Than or Equal to K](https://leetcode.com/problems/maximum-number-that-sum-of-the-prices-is-less-than-or-equal-to-k/description/)

## Description

You are given an integer `k` and an integer `x`. The price of a number`num` is calculated by the count of set bits at positions `x`, `2x`, `3x`, etc., in its binary representation, starting from the least significant bit. The following table contains examples of how price is calculated.

<table><tbody><tr><th>x</th><th>num</th><th>Binary Representation</th><th>Price</th></tr><tr><td>1</td><td>13</td><td>00000<b>11</b>0<b>1</b> </td><td>3</td></tr><tr><td>2</td><td>13</td><td>00000<b>1</b>101</td><td>1</td></tr><tr><td>2</td><td>233</td><td>0<b>1</b>1<b>1</b>0<b>1</b>001</td><td>3</td></tr><tr><td>3</td><td>13</td><td>000001<b>1</b>01</td><td>1</td></tr><tr><td>3</td><td>362</td><td><b>1</b>01<b>1</b>01010</td><td>2</td></tr></tbody></table>

The **accumulated price** of`num`is the **total** price of numbers from `1` to `num`. `num` is considered **cheap** if its accumulated price is less than or equal to `k`.

Return the **greatest** cheap number.

**Example 1:**

<div class="example-block">
Input: k = 9, x = 1

Output: 6

Explanation:

As shown in the table below, `6` is the greatest cheap number.

<table border="1"><tbody><tr><th>x</th><th>num</th><th>Binary Representation</th><th>Price</th><th>Accumulated Price</th></tr><tr><td>1</td><td>1</td><td>00<b>1</b></td><td>1</td><td>1</td></tr><tr><td>1</td><td>2</td><td>0<b>1</b>0</td><td>1</td><td>2</td></tr><tr><td>1</td><td>3</td><td>0<b>11</b></td><td>2</td><td>4</td></tr><tr><td>1</td><td>4</td><td><b>1</b>00</td><td>1</td><td>5</td></tr><tr><td>1</td><td>5</td><td><b>1</b>0<b>1</b></td><td>2</td><td>7</td></tr><tr><td>1</td><td>6</td><td><b>11</b>0</td><td>2</td><td>9</td></tr><tr><td>1</td><td>7</td><td><b>111</b></td><td>3</td><td>12</td></tr></tbody></table>

**Example 2:**

<div class="example-block">
Input: k = 7, x = 2

Output: 9

Explanation:

As shown in the table below, `9` is the greatest cheap number.

<table border="1"><tbody><tr><th>x</th><th>num</th><th>Binary Representation</th><th>Price</th><th>Accumulated Price</th></tr><tr><td>2</td><td>1</td><td>0001</td><td>0</td><td>0</td></tr><tr><td>2</td><td>2</td><td>00<B>1</B>0</td><td>1</td><td>1</td></tr><tr><td>2</td><td>3</td><td>00<B>1</B>1</td><td>1</td><td>2</td></tr><tr><td>2</td><td>4</td><td>0100</td><td>0</td><td>2</td></tr><tr><td>2</td><td>5</td><td>0101</td><td>0</td><td>2</td></tr><tr><td>2</td><td>6</td><td>01<B>1</B>0</td><td>1</td><td>3</td></tr><tr><td>2</td><td>7</td><td>01<B>1</B>1</td><td>1</td><td>4</td></tr><tr><td>2</td><td>8</td><td><B>1</B>000</td><td>1</td><td>5</td></tr><tr><td>2</td><td>9</td><td><B>1</B>001</td><td>1</td><td>6</td></tr><tr><td>2</td><td>10</td><td><B>1</B>0<B>1</B>0</td><td>2</td><td>8</td></tr></tbody></table>

**Constraints:**

- `1 <= k <= 10^15`
- `1 <= x <= 8`

## Hints/Notes

- 2024/11/23
- Binary search + digit dp
- [0x3F's solution](https://leetcode.cn/problems/maximum-number-that-sum-of-the-prices-is-less-than-or-equal-to-k/solutions/2603673/er-fen-da-an-shu-wei-dpwei-yun-suan-pyth-tkir/)(checked)
- Weekly Contest 380

## Solution

Language: **C++**

```C++
class Solution {
public:
    long long num;
    int x, n;
    vector<vector<long long>> dp;

    long long findMaximumNumber(long long k, int x) {
        this->x = x;
        long long left = 0, right = (k + 1) << x;
        while (left + 1 < right) {
            long long mid = left + (right - left) / 2;
            if (f(mid) > k) {
                right = mid;
            } else {
                left = mid;
            }
        }
        return left;
    }

    long long f(long long num) {
        this->num = num;
        n = __lg(num);
        dp.resize(n + 1, vector<long long>(n + 1, -1));
        long long res = dfs(n, 0, true);
        return res;
    }

    long long dfs(int index, int price, int limit_high) {
        if (index == -1) {
            return price;
        }
        if (!limit_high && dp[index][price] != -1) {
            return dp[index][price];
        }
        int hi = limit_high ? (num >> index) & 1 : 1;
        long long res = 0;
        for (int i = 0; i <= hi; i++) {
            int tmp = 0;
            if ((index + 1) % x == 0) {
                tmp = i;
            }
            res += dfs(index - 1, price + tmp, limit_high && i == hi);
        }
        if (!limit_high) {
            dp[index][price] = res;
        }
        return res;
    }
};
```
