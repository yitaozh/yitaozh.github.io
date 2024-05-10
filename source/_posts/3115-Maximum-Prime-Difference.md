---
title: 3115. Maximum Prime Difference
categories: Leetcode
date: 2024-05-10 14:02:45
tags:
    - Array
    - Math
    - Number Theory
---

[3115. Maximum Prime Difference](https://leetcode.com/problems/maximum-prime-difference/description/)

## Description

You are given an integer array `nums`.

Return an integer that is the **maximum**  distance between the **indices**  of two (not necessarily different) prime numbers in `nums`.

**Example 1:**

```bash
Input: nums = [4,2,9,5,3]

Output: 3

Explanation: `nums[1]`, `nums[3]`, and `nums[4]` are prime. So the answer is `|4 - 1| = 3`.
```

**Example 2:**

```bash
Input: nums = [4,8,2,8]

Output: 0

Explanation: `nums[2]` is prime. Because there is just one prime number, the answer is `|2 - 2| = 0`.
```

**Constraints:**

- `1 <= nums.length <= 3 * 10^5`
- `1 <= nums[i] <= 100`
- The input is generated such that the number of prime numbers in the `nums` is at least one.

## Hints/Notes

- two pointers, from beginning and end of the array

## Solution

Language: **C++**

```C++
class Solution {
public:
    map<int, bool> prime;

    int maximumPrimeDifference(vector<int>& nums) {
        int low = 0, high = nums.size() - 1;
        prime[1] = false;
        prime[2] = true;
        while (low <= high) {
            bool isPrimeLow = primeNumber(nums[low]);
            bool isPrimeHigh = primeNumber(nums[high]);
            if (isPrimeLow && isPrimeHigh) {
                return high - low;
            }
            if (!isPrimeLow) {
                low++;
            }
            if (!isPrimeHigh) {
                high--;
            }
        }
        return 0;
    }

    bool primeNumber(int num) {
        if (prime.contains(num)) {
            return prime[num];
        }
        for (int i = 2; i * i <= num; i++) {
            if (num % i == 0) {
                prime[num] = false;
                return false;
            }
        }
        prime[num] = true;
        return true;
    }
};
```
