---
title: 313. Super Ugly Number
categories: Leetcode
date: 2023-11-06 18:19:55
tags:
    - Array
    - Match
    - Dynamic Programming
---

# [313\. Super Ugly Number](https://leetcode.com/problems/super-ugly-number/)

## Description

Difficulty: **Medium**

Related Topics: [Array](https://leetcode.com/tag/https://leetcode.com/tag/array//), [Math](https://leetcode.com/tag/https://leetcode.com/tag/math//), [Dynamic Programming](https://leetcode.com/tag/https://leetcode.com/tag/dynamic-programming//)

A **super ugly number** is a positive integer whose prime factors are in the array `primes`.

Given an integer `n` and an array of integers `primes`, return _the_ n<sup>th</sup> _**super ugly number**_.

The n<sup>th</sup> **super ugly number** is **guaranteed** to fit in a **32-bit** signed integer.

**Example 1:**

```bash
Input: n = 12, primes = [2,7,13,19]
Output: 32
Explanation: [1,2,4,7,8,13,14,16,19,26,28,32] is the sequence of the first 12 super ugly numbers given primes = [2,7,13,19].
```

**Example 2:**

```bash
Input: n = 1, primes = [2,3,5]
Output: 1
Explanation: 1 has no prime factors, therefore all of its prime factors are in the array primes = [2,3,5].
```

**Constraints:**

* 1 <= n <= 10<sup>5</sup>
* `1 <= primes.length <= 100`
* `2 <= primes[i] <= 1000`
* `primes[i]` is **guaranteed** to be a prime number.
* All the values of `primes` are **unique** and sorted in **ascending order**.

## Hints/Notes

* priority queue

## Solution

Language: **C++**

```C++
class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        priority_queue<vector<long>, vector<vector<long>>, greater<vector<long>>> pq;
        vector<long> res;
        for (int prime : primes) {
            pq.push({1, 0, prime});
        }
        while (res.size() < n) {
            long val = pq.top()[0];
            res.push_back(val);
            while (pq.top()[0] == val) {
                int idx = pq.top()[1];
                int prime = pq.top()[2];
                pq.pop();
                pq.push({res[idx] * prime, idx + 1, prime});
            }
        }
        return res.back();
    }
};
```
