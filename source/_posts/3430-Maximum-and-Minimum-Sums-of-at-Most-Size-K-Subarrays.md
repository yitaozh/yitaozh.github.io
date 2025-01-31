---
title: 3430. Maximum and Minimum Sums of at Most Size K Subarrays
categories: Leetcode
date: 2025-01-27 12:56:07
tags:
    - Array
    - Math
    - Stack
    - Monotonic Stack
---

[3430. Maximum and Minimum Sums of at Most Size K Subarrays](https://leetcode.com/problems/maximum-and-minimum-sums-of-at-most-size-k-subarrays/description/)

## Description

You are given an integer array `nums` and a **positive**  integer `k`. Return the sum of the **maximum**  and **minimum**  elements of all subarrays with **at most**  `k` elements.

**Example 1:**

```bash
Input: nums = [1,2,3], k = 2

Output: 20
```

Explanation:

The subarrays of `nums` with at most 2 elements are:

<table style="border: 1px solid black; --darkreader-inline-border-top: #d2c3ad; --darkreader-inline-border-right: #d2c3ad; --darkreader-inline-border-bottom: #d2c3ad; --darkreader-inline-border-left: #d2c3ad;" data-darkreader-inline-border-top="" data-darkreader-inline-border-right="" data-darkreader-inline-border-bottom="" data-darkreader-inline-border-left=""><tbody><tr><th style="border: 1px solid black; --darkreader-inline-border-top: #d2c3ad; --darkreader-inline-border-right: #d2c3ad; --darkreader-inline-border-bottom: #d2c3ad; --darkreader-inline-border-left: #d2c3ad;" data-darkreader-inline-border-top="" data-darkreader-inline-border-right="" data-darkreader-inline-border-bottom="" data-darkreader-inline-border-left=""><b>Subarray</b></th><th style="border: 1px solid black; --darkreader-inline-border-top: #d2c3ad; --darkreader-inline-border-right: #d2c3ad; --darkreader-inline-border-bottom: #d2c3ad; --darkreader-inline-border-left: #d2c3ad;" data-darkreader-inline-border-top="" data-darkreader-inline-border-right="" data-darkreader-inline-border-bottom="" data-darkreader-inline-border-left="">Minimum</th><th style="border: 1px solid black; --darkreader-inline-border-top: #d2c3ad; --darkreader-inline-border-right: #d2c3ad; --darkreader-inline-border-bottom: #d2c3ad; --darkreader-inline-border-left: #d2c3ad;" data-darkreader-inline-border-top="" data-darkreader-inline-border-right="" data-darkreader-inline-border-bottom="" data-darkreader-inline-border-left="">Maximum</th><th style="border: 1px solid black; --darkreader-inline-border-top: #d2c3ad; --darkreader-inline-border-right: #d2c3ad; --darkreader-inline-border-bottom: #d2c3ad; --darkreader-inline-border-left: #d2c3ad;" data-darkreader-inline-border-top="" data-darkreader-inline-border-right="" data-darkreader-inline-border-bottom="" data-darkreader-inline-border-left="">Sum</th></tr><tr><td style="border: 1px solid black; --darkreader-inline-border-top: #d2c3ad; --darkreader-inline-border-right: #d2c3ad; --darkreader-inline-border-bottom: #d2c3ad; --darkreader-inline-border-left: #d2c3ad;" data-darkreader-inline-border-top="" data-darkreader-inline-border-right="" data-darkreader-inline-border-bottom="" data-darkreader-inline-border-left="">[1]</td><td style="border: 1px solid black; --darkreader-inline-border-top: #d2c3ad; --darkreader-inline-border-right: #d2c3ad; --darkreader-inline-border-bottom: #d2c3ad; --darkreader-inline-border-left: #d2c3ad;" data-darkreader-inline-border-top="" data-darkreader-inline-border-right="" data-darkreader-inline-border-bottom="" data-darkreader-inline-border-left="">1</td><td style="border: 1px solid black; --darkreader-inline-border-top: #d2c3ad; --darkreader-inline-border-right: #d2c3ad; --darkreader-inline-border-bottom: #d2c3ad; --darkreader-inline-border-left: #d2c3ad;" data-darkreader-inline-border-top="" data-darkreader-inline-border-right="" data-darkreader-inline-border-bottom="" data-darkreader-inline-border-left="">1</td><td style="border: 1px solid black; --darkreader-inline-border-top: #d2c3ad; --darkreader-inline-border-right: #d2c3ad; --darkreader-inline-border-bottom: #d2c3ad; --darkreader-inline-border-left: #d2c3ad;" data-darkreader-inline-border-top="" data-darkreader-inline-border-right="" data-darkreader-inline-border-bottom="" data-darkreader-inline-border-left="">2</td></tr><tr><td style="border: 1px solid black; --darkreader-inline-border-top: #d2c3ad; --darkreader-inline-border-right: #d2c3ad; --darkreader-inline-border-bottom: #d2c3ad; --darkreader-inline-border-left: #d2c3ad;" data-darkreader-inline-border-top="" data-darkreader-inline-border-right="" data-darkreader-inline-border-bottom="" data-darkreader-inline-border-left="">[2]</td><td style="border: 1px solid black; --darkreader-inline-border-top: #d2c3ad; --darkreader-inline-border-right: #d2c3ad; --darkreader-inline-border-bottom: #d2c3ad; --darkreader-inline-border-left: #d2c3ad;" data-darkreader-inline-border-top="" data-darkreader-inline-border-right="" data-darkreader-inline-border-bottom="" data-darkreader-inline-border-left="">2</td><td style="border: 1px solid black; --darkreader-inline-border-top: #d2c3ad; --darkreader-inline-border-right: #d2c3ad; --darkreader-inline-border-bottom: #d2c3ad; --darkreader-inline-border-left: #d2c3ad;" data-darkreader-inline-border-top="" data-darkreader-inline-border-right="" data-darkreader-inline-border-bottom="" data-darkreader-inline-border-left="">2</td><td style="border: 1px solid black; --darkreader-inline-border-top: #d2c3ad; --darkreader-inline-border-right: #d2c3ad; --darkreader-inline-border-bottom: #d2c3ad; --darkreader-inline-border-left: #d2c3ad;" data-darkreader-inline-border-top="" data-darkreader-inline-border-right="" data-darkreader-inline-border-bottom="" data-darkreader-inline-border-left="">4</td></tr><tr><td style="border: 1px solid black; --darkreader-inline-border-top: #d2c3ad; --darkreader-inline-border-right: #d2c3ad; --darkreader-inline-border-bottom: #d2c3ad; --darkreader-inline-border-left: #d2c3ad;" data-darkreader-inline-border-top="" data-darkreader-inline-border-right="" data-darkreader-inline-border-bottom="" data-darkreader-inline-border-left="">[3]</td><td style="border: 1px solid black; --darkreader-inline-border-top: #d2c3ad; --darkreader-inline-border-right: #d2c3ad; --darkreader-inline-border-bottom: #d2c3ad; --darkreader-inline-border-left: #d2c3ad;" data-darkreader-inline-border-top="" data-darkreader-inline-border-right="" data-darkreader-inline-border-bottom="" data-darkreader-inline-border-left="">3</td><td style="border: 1px solid black; --darkreader-inline-border-top: #d2c3ad; --darkreader-inline-border-right: #d2c3ad; --darkreader-inline-border-bottom: #d2c3ad; --darkreader-inline-border-left: #d2c3ad;" data-darkreader-inline-border-top="" data-darkreader-inline-border-right="" data-darkreader-inline-border-bottom="" data-darkreader-inline-border-left="">3</td><td style="border: 1px solid black; --darkreader-inline-border-top: #d2c3ad; --darkreader-inline-border-right: #d2c3ad; --darkreader-inline-border-bottom: #d2c3ad; --darkreader-inline-border-left: #d2c3ad;" data-darkreader-inline-border-top="" data-darkreader-inline-border-right="" data-darkreader-inline-border-bottom="" data-darkreader-inline-border-left="">6</td></tr><tr><td style="border: 1px solid black; --darkreader-inline-border-top: #d2c3ad; --darkreader-inline-border-right: #d2c3ad; --darkreader-inline-border-bottom: #d2c3ad; --darkreader-inline-border-left: #d2c3ad;" data-darkreader-inline-border-top="" data-darkreader-inline-border-right="" data-darkreader-inline-border-bottom="" data-darkreader-inline-border-left="">[1, 2]</td><td style="border: 1px solid black; --darkreader-inline-border-top: #d2c3ad; --darkreader-inline-border-right: #d2c3ad; --darkreader-inline-border-bottom: #d2c3ad; --darkreader-inline-border-left: #d2c3ad;" data-darkreader-inline-border-top="" data-darkreader-inline-border-right="" data-darkreader-inline-border-bottom="" data-darkreader-inline-border-left="">1</td><td style="border: 1px solid black; --darkreader-inline-border-top: #d2c3ad; --darkreader-inline-border-right: #d2c3ad; --darkreader-inline-border-bottom: #d2c3ad; --darkreader-inline-border-left: #d2c3ad;" data-darkreader-inline-border-top="" data-darkreader-inline-border-right="" data-darkreader-inline-border-bottom="" data-darkreader-inline-border-left="">2</td><td style="border: 1px solid black; --darkreader-inline-border-top: #d2c3ad; --darkreader-inline-border-right: #d2c3ad; --darkreader-inline-border-bottom: #d2c3ad; --darkreader-inline-border-left: #d2c3ad;" data-darkreader-inline-border-top="" data-darkreader-inline-border-right="" data-darkreader-inline-border-bottom="" data-darkreader-inline-border-left="">3</td></tr><tr><td style="border: 1px solid black; --darkreader-inline-border-top: #d2c3ad; --darkreader-inline-border-right: #d2c3ad; --darkreader-inline-border-bottom: #d2c3ad; --darkreader-inline-border-left: #d2c3ad;" data-darkreader-inline-border-top="" data-darkreader-inline-border-right="" data-darkreader-inline-border-bottom="" data-darkreader-inline-border-left="">[2, 3]</td><td style="border: 1px solid black; --darkreader-inline-border-top: #d2c3ad; --darkreader-inline-border-right: #d2c3ad; --darkreader-inline-border-bottom: #d2c3ad; --darkreader-inline-border-left: #d2c3ad;" data-darkreader-inline-border-top="" data-darkreader-inline-border-right="" data-darkreader-inline-border-bottom="" data-darkreader-inline-border-left="">2</td><td style="border: 1px solid black; --darkreader-inline-border-top: #d2c3ad; --darkreader-inline-border-right: #d2c3ad; --darkreader-inline-border-bottom: #d2c3ad; --darkreader-inline-border-left: #d2c3ad;" data-darkreader-inline-border-top="" data-darkreader-inline-border-right="" data-darkreader-inline-border-bottom="" data-darkreader-inline-border-left="">3</td><td style="border: 1px solid black; --darkreader-inline-border-top: #d2c3ad; --darkreader-inline-border-right: #d2c3ad; --darkreader-inline-border-bottom: #d2c3ad; --darkreader-inline-border-left: #d2c3ad;" data-darkreader-inline-border-top="" data-darkreader-inline-border-right="" data-darkreader-inline-border-bottom="" data-darkreader-inline-border-left="">5</td></tr><tr><td style="border: 1px solid black; --darkreader-inline-border-top: #d2c3ad; --darkreader-inline-border-right: #d2c3ad; --darkreader-inline-border-bottom: #d2c3ad; --darkreader-inline-border-left: #d2c3ad;" data-darkreader-inline-border-top="" data-darkreader-inline-border-right="" data-darkreader-inline-border-bottom="" data-darkreader-inline-border-left="">Final Total</td><td style="border: 1px solid black; --darkreader-inline-border-top: #d2c3ad; --darkreader-inline-border-right: #d2c3ad; --darkreader-inline-border-bottom: #d2c3ad; --darkreader-inline-border-left: #d2c3ad;" data-darkreader-inline-border-top="" data-darkreader-inline-border-right="" data-darkreader-inline-border-bottom="" data-darkreader-inline-border-left=""></td><td style="border: 1px solid black; --darkreader-inline-border-top: #d2c3ad; --darkreader-inline-border-right: #d2c3ad; --darkreader-inline-border-bottom: #d2c3ad; --darkreader-inline-border-left: #d2c3ad;" data-darkreader-inline-border-top="" data-darkreader-inline-border-right="" data-darkreader-inline-border-bottom="" data-darkreader-inline-border-left=""></td><td style="border: 1px solid black; --darkreader-inline-border-top: #d2c3ad; --darkreader-inline-border-right: #d2c3ad; --darkreader-inline-border-bottom: #d2c3ad; --darkreader-inline-border-left: #d2c3ad;" data-darkreader-inline-border-top="" data-darkreader-inline-border-right="" data-darkreader-inline-border-bottom="" data-darkreader-inline-border-left="">20</td></tr></tbody></table>

The output would be 20.

**Example 2:**

<div class="example-block">
Input: nums = [1,-3,1], k = 2

Output: -6

Explanation:

The subarrays of `nums` with at most 2 elements are:

<table style="border: 1px solid black; --darkreader-inline-border-top: #d2c3ad; --darkreader-inline-border-right: #d2c3ad; --darkreader-inline-border-bottom: #d2c3ad; --darkreader-inline-border-left: #d2c3ad;" data-darkreader-inline-border-top="" data-darkreader-inline-border-right="" data-darkreader-inline-border-bottom="" data-darkreader-inline-border-left=""><tbody><tr><th style="border: 1px solid black; --darkreader-inline-border-top: #d2c3ad; --darkreader-inline-border-right: #d2c3ad; --darkreader-inline-border-bottom: #d2c3ad; --darkreader-inline-border-left: #d2c3ad;" data-darkreader-inline-border-top="" data-darkreader-inline-border-right="" data-darkreader-inline-border-bottom="" data-darkreader-inline-border-left=""><b>Subarray</b></th><th style="border: 1px solid black; --darkreader-inline-border-top: #d2c3ad; --darkreader-inline-border-right: #d2c3ad; --darkreader-inline-border-bottom: #d2c3ad; --darkreader-inline-border-left: #d2c3ad;" data-darkreader-inline-border-top="" data-darkreader-inline-border-right="" data-darkreader-inline-border-bottom="" data-darkreader-inline-border-left="">Minimum</th><th style="border: 1px solid black; --darkreader-inline-border-top: #d2c3ad; --darkreader-inline-border-right: #d2c3ad; --darkreader-inline-border-bottom: #d2c3ad; --darkreader-inline-border-left: #d2c3ad;" data-darkreader-inline-border-top="" data-darkreader-inline-border-right="" data-darkreader-inline-border-bottom="" data-darkreader-inline-border-left="">Maximum</th><th style="border: 1px solid black; --darkreader-inline-border-top: #d2c3ad; --darkreader-inline-border-right: #d2c3ad; --darkreader-inline-border-bottom: #d2c3ad; --darkreader-inline-border-left: #d2c3ad;" data-darkreader-inline-border-top="" data-darkreader-inline-border-right="" data-darkreader-inline-border-bottom="" data-darkreader-inline-border-left="">Sum</th></tr><tr><td style="border: 1px solid black; --darkreader-inline-border-top: #d2c3ad; --darkreader-inline-border-right: #d2c3ad; --darkreader-inline-border-bottom: #d2c3ad; --darkreader-inline-border-left: #d2c3ad;" data-darkreader-inline-border-top="" data-darkreader-inline-border-right="" data-darkreader-inline-border-bottom="" data-darkreader-inline-border-left="">[1]</td><td style="border: 1px solid black; --darkreader-inline-border-top: #d2c3ad; --darkreader-inline-border-right: #d2c3ad; --darkreader-inline-border-bottom: #d2c3ad; --darkreader-inline-border-left: #d2c3ad;" data-darkreader-inline-border-top="" data-darkreader-inline-border-right="" data-darkreader-inline-border-bottom="" data-darkreader-inline-border-left="">1</td><td style="border: 1px solid black; --darkreader-inline-border-top: #d2c3ad; --darkreader-inline-border-right: #d2c3ad; --darkreader-inline-border-bottom: #d2c3ad; --darkreader-inline-border-left: #d2c3ad;" data-darkreader-inline-border-top="" data-darkreader-inline-border-right="" data-darkreader-inline-border-bottom="" data-darkreader-inline-border-left="">1</td><td style="border: 1px solid black; --darkreader-inline-border-top: #d2c3ad; --darkreader-inline-border-right: #d2c3ad; --darkreader-inline-border-bottom: #d2c3ad; --darkreader-inline-border-left: #d2c3ad;" data-darkreader-inline-border-top="" data-darkreader-inline-border-right="" data-darkreader-inline-border-bottom="" data-darkreader-inline-border-left="">2</td></tr><tr><td style="border: 1px solid black; --darkreader-inline-border-top: #d2c3ad; --darkreader-inline-border-right: #d2c3ad; --darkreader-inline-border-bottom: #d2c3ad; --darkreader-inline-border-left: #d2c3ad;" data-darkreader-inline-border-top="" data-darkreader-inline-border-right="" data-darkreader-inline-border-bottom="" data-darkreader-inline-border-left="">[-3]</td><td style="border: 1px solid black; --darkreader-inline-border-top: #d2c3ad; --darkreader-inline-border-right: #d2c3ad; --darkreader-inline-border-bottom: #d2c3ad; --darkreader-inline-border-left: #d2c3ad;" data-darkreader-inline-border-top="" data-darkreader-inline-border-right="" data-darkreader-inline-border-bottom="" data-darkreader-inline-border-left="">-3</td><td style="border: 1px solid black; --darkreader-inline-border-top: #d2c3ad; --darkreader-inline-border-right: #d2c3ad; --darkreader-inline-border-bottom: #d2c3ad; --darkreader-inline-border-left: #d2c3ad;" data-darkreader-inline-border-top="" data-darkreader-inline-border-right="" data-darkreader-inline-border-bottom="" data-darkreader-inline-border-left="">-3</td><td style="border: 1px solid black; --darkreader-inline-border-top: #d2c3ad; --darkreader-inline-border-right: #d2c3ad; --darkreader-inline-border-bottom: #d2c3ad; --darkreader-inline-border-left: #d2c3ad;" data-darkreader-inline-border-top="" data-darkreader-inline-border-right="" data-darkreader-inline-border-bottom="" data-darkreader-inline-border-left="">-6</td></tr><tr><td style="border: 1px solid black; --darkreader-inline-border-top: #d2c3ad; --darkreader-inline-border-right: #d2c3ad; --darkreader-inline-border-bottom: #d2c3ad; --darkreader-inline-border-left: #d2c3ad;" data-darkreader-inline-border-top="" data-darkreader-inline-border-right="" data-darkreader-inline-border-bottom="" data-darkreader-inline-border-left="">[1]</td><td style="border: 1px solid black; --darkreader-inline-border-top: #d2c3ad; --darkreader-inline-border-right: #d2c3ad; --darkreader-inline-border-bottom: #d2c3ad; --darkreader-inline-border-left: #d2c3ad;" data-darkreader-inline-border-top="" data-darkreader-inline-border-right="" data-darkreader-inline-border-bottom="" data-darkreader-inline-border-left="">1</td><td style="border: 1px solid black; --darkreader-inline-border-top: #d2c3ad; --darkreader-inline-border-right: #d2c3ad; --darkreader-inline-border-bottom: #d2c3ad; --darkreader-inline-border-left: #d2c3ad;" data-darkreader-inline-border-top="" data-darkreader-inline-border-right="" data-darkreader-inline-border-bottom="" data-darkreader-inline-border-left="">1</td><td style="border: 1px solid black; --darkreader-inline-border-top: #d2c3ad; --darkreader-inline-border-right: #d2c3ad; --darkreader-inline-border-bottom: #d2c3ad; --darkreader-inline-border-left: #d2c3ad;" data-darkreader-inline-border-top="" data-darkreader-inline-border-right="" data-darkreader-inline-border-bottom="" data-darkreader-inline-border-left="">2</td></tr><tr><td style="border: 1px solid black; --darkreader-inline-border-top: #d2c3ad; --darkreader-inline-border-right: #d2c3ad; --darkreader-inline-border-bottom: #d2c3ad; --darkreader-inline-border-left: #d2c3ad;" data-darkreader-inline-border-top="" data-darkreader-inline-border-right="" data-darkreader-inline-border-bottom="" data-darkreader-inline-border-left="">[1, -3]</td><td style="border: 1px solid black; --darkreader-inline-border-top: #d2c3ad; --darkreader-inline-border-right: #d2c3ad; --darkreader-inline-border-bottom: #d2c3ad; --darkreader-inline-border-left: #d2c3ad;" data-darkreader-inline-border-top="" data-darkreader-inline-border-right="" data-darkreader-inline-border-bottom="" data-darkreader-inline-border-left="">-3</td><td style="border: 1px solid black; --darkreader-inline-border-top: #d2c3ad; --darkreader-inline-border-right: #d2c3ad; --darkreader-inline-border-bottom: #d2c3ad; --darkreader-inline-border-left: #d2c3ad;" data-darkreader-inline-border-top="" data-darkreader-inline-border-right="" data-darkreader-inline-border-bottom="" data-darkreader-inline-border-left="">1</td><td style="border: 1px solid black; --darkreader-inline-border-top: #d2c3ad; --darkreader-inline-border-right: #d2c3ad; --darkreader-inline-border-bottom: #d2c3ad; --darkreader-inline-border-left: #d2c3ad;" data-darkreader-inline-border-top="" data-darkreader-inline-border-right="" data-darkreader-inline-border-bottom="" data-darkreader-inline-border-left="">-2</td></tr><tr><td style="border: 1px solid black; --darkreader-inline-border-top: #d2c3ad; --darkreader-inline-border-right: #d2c3ad; --darkreader-inline-border-bottom: #d2c3ad; --darkreader-inline-border-left: #d2c3ad;" data-darkreader-inline-border-top="" data-darkreader-inline-border-right="" data-darkreader-inline-border-bottom="" data-darkreader-inline-border-left="">[-3, 1]</td><td style="border: 1px solid black; --darkreader-inline-border-top: #d2c3ad; --darkreader-inline-border-right: #d2c3ad; --darkreader-inline-border-bottom: #d2c3ad; --darkreader-inline-border-left: #d2c3ad;" data-darkreader-inline-border-top="" data-darkreader-inline-border-right="" data-darkreader-inline-border-bottom="" data-darkreader-inline-border-left="">-3</td><td style="border: 1px solid black; --darkreader-inline-border-top: #d2c3ad; --darkreader-inline-border-right: #d2c3ad; --darkreader-inline-border-bottom: #d2c3ad; --darkreader-inline-border-left: #d2c3ad;" data-darkreader-inline-border-top="" data-darkreader-inline-border-right="" data-darkreader-inline-border-bottom="" data-darkreader-inline-border-left="">1</td><td style="border: 1px solid black; --darkreader-inline-border-top: #d2c3ad; --darkreader-inline-border-right: #d2c3ad; --darkreader-inline-border-bottom: #d2c3ad; --darkreader-inline-border-left: #d2c3ad;" data-darkreader-inline-border-top="" data-darkreader-inline-border-right="" data-darkreader-inline-border-bottom="" data-darkreader-inline-border-left="">-2</td></tr><tr><td style="border: 1px solid black; --darkreader-inline-border-top: #d2c3ad; --darkreader-inline-border-right: #d2c3ad; --darkreader-inline-border-bottom: #d2c3ad; --darkreader-inline-border-left: #d2c3ad;" data-darkreader-inline-border-top="" data-darkreader-inline-border-right="" data-darkreader-inline-border-bottom="" data-darkreader-inline-border-left="">Final Total </td><td style="border: 1px solid black; --darkreader-inline-border-top: #d2c3ad; --darkreader-inline-border-right: #d2c3ad; --darkreader-inline-border-bottom: #d2c3ad; --darkreader-inline-border-left: #d2c3ad;" data-darkreader-inline-border-top="" data-darkreader-inline-border-right="" data-darkreader-inline-border-bottom="" data-darkreader-inline-border-left=""></td><td style="border: 1px solid black; --darkreader-inline-border-top: #d2c3ad; --darkreader-inline-border-right: #d2c3ad; --darkreader-inline-border-bottom: #d2c3ad; --darkreader-inline-border-left: #d2c3ad;" data-darkreader-inline-border-top="" data-darkreader-inline-border-right="" data-darkreader-inline-border-bottom="" data-darkreader-inline-border-left=""></td><td style="border: 1px solid black; --darkreader-inline-border-top: #d2c3ad; --darkreader-inline-border-right: #d2c3ad; --darkreader-inline-border-bottom: #d2c3ad; --darkreader-inline-border-left: #d2c3ad;" data-darkreader-inline-border-top="" data-darkreader-inline-border-right="" data-darkreader-inline-border-bottom="" data-darkreader-inline-border-left="">-6</td></tr></tbody></table>

The output would be -6.

**Constraints:**

- `1 <= nums.length <= 80000`
- `1 <= k <= nums.length`
- `-10^6 <= nums[i] <= 10^6`

## Hints/Notes

- 2025/01/26
- monotonic stack
- [0x3F's solution](https://leetcode.cn/problems/maximum-and-minimum-sums-of-at-most-size-k-subarrays/description/)
- Weekly Contest 433

## Solution

Language: **C++**

```C++
class Solution {
public:
    long long minMaxSubarraySum(vector<int>& nums, int k) {
        deque<pair<int, int>> q;
        int n = nums.size();
        long long res = 0;
        long long cur = 0;
        // the question here is: for each element as the rightmost element,
        // the maximum number in the min(index + 1, k) subarrays
        // when we take in a new number, we check if it's the biggest number
        // in the last k numbers:
        // 1. if it is, then it would be the largest element for all subarrays
        // sized from 1 to k, push a (val, k) into the stk
        // 2. if it's not, then idx - prevIdx is the number of subarrays that it
        // is the largest element
        // 3. we add the val * num into cur, and we only need to add that value
        // into the res
        for (int i = 0; i < n; i++) {
            if (!q.empty()) {
                if (i >= k) {
                    q.front().second--;
                    cur -= nums[q.front().first];
                }
                if (q.front().first <= i - k) {
                    q.pop_front();
                }
            }
            while (!q.empty() && nums[i] > nums[q.back().first]) {
                cur -= (long long)nums[q.back().first] * q.back().second;
                q.pop_back();
            }
            if (q.empty()) {
                q.push_back({i, min(i + 1, k)});
            } else {
                int idx = q.back().first;
                q.push_back({i, i - idx});
            }
            cur += (long long)nums[q.back().first] * q.back().second;
            res += cur;
        }
        cout << res << endl;
        q.clear();
        cur = 0;
        for (int i = 0; i < n; i++) {
            if (!q.empty()) {
                if (i >= k) {
                    q.front().second--;
                    cur -= nums[q.front().first];
                }
                if (q.front().first <= i - k) {
                    q.pop_front();
                }
            }
            while (!q.empty() && nums[i] < nums[q.back().first]) {
                cur -= (long long)nums[q.back().first] * q.back().second;
                q.pop_back();
            }
            if (q.empty()) {
                q.push_back({i, min(i + 1, k)});
            } else {
                int idx = q.back().first;
                q.push_back({i, i - idx});
            }
            cur += (long long)nums[q.back().first] * q.back().second;
            res += cur;
        }
        return res;
    }
};
```
