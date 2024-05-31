---
title: 608B. Hamming Distance Sum
categories: Leetcode
date: 2024-05-30 23:35:17
tags:
    - Combinatorics
    - String
---

[B. Hamming Distance Sum](https://codeforces.com/problemset/problem/608/B)

## Description

输入长度均 ≤2e5 的字符串 s 和 t，只包含 '0' 和 '1'。并且 t 的长度大于等于 s 的长度。

定义 D(a,b) = |a[0]-b[0]| + |a[1]-b[1]| + ... + |a[n-1]-b[n-1]|。
例如 D("0011", "0110") = |0-0| + |0-1| + |1-1| + |1-0| = 0 + 1 + 0 + 1 = 2。

设 s 的长度为 n，对于 t 的所有长为 n 的连续子串 t'，计算 D(s,t')。
输出所有 D(s,t') 的和。

进阶：额外输入 k，计算 s 所有长为 k 的子串与 t 的所有长为 k 的子串的 D 之和。

## Hints/Notes

- think how each element contribute to the final result

## Solution

Language: **C++**

```C++

```
