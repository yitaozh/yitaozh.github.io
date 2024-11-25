---
title: 3164. Find the Number of Good Pairs II
categories: Leetcode
date: 2024-05-30 12:25:33
tags:
    - Array
    - Hash Table
---

[3164. Find the Number of Good Pairs II](https://leetcode.com/problems/find-the-number-of-good-pairs-ii/description/)

## Description

You are given 2 integer arrays `nums1` and `nums2` of lengths `n` and `m` respectively. You are also given a **positive**  integer `k`.

A pair `(i, j)` is called **good**  if `nums1[i]` is divisible by `nums2[j] * k` (`0 <= i <= n - 1`, `0 <= j <= m - 1`).

Return the total number of **good**  pairs.

**Example 1:**

```bash
Input: nums1 = [1,3,4], nums2 = [1,3,4], k = 1

Output: 5

Explanation:
The 5 good pairs are `(0, 0)`, `(1, 0)`, `(1, 1)`, `(2, 0)`, and `(2, 2)`.
```

**Example 2:**

```bash
Input: nums1 = [1,2,4,12], nums2 = [2,4], k = 3

Output: 2

Explanation:

The 2 good pairs are `(3, 0)` and `(3, 1)`.
```

**Constraints:**

- `1 <= n, m <= 10^5`
- `1 <= nums1[i], nums2[j] <= 10^6`
- `1 <= k <= 10^3`

## Hints/Notes

- 2024/03/01
- [0x3F's solution](https://leetcode.cn/problems/find-the-number-of-good-pairs-ii/solutions/2790631/tong-ji-yin-zi-ge-shu-pythonjavacgo-by-e-bl3o/)(checked)
- Weekly Contest 399

## Solution

Language: **C++**

```C++
class Solution {
public:
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        // since nums1[i] needs to be divisible by k, just divide the nums1 by k and record
        // the numbers in candidates
        unordered_map<int, int> m1, m2;
        for (auto& num1 : nums1) {
            if (num1 % k == 0) {
                m1[num1 / k]++;
            }
        }
        if (m1.empty()) {
            return 0;
        }
        for (auto& num2 : nums2) {
            m2[num2]++;
        }
        int mx = ranges::max_element(m1)->first;
        long long res = 0;
        for (auto& [num2, count] : m2) {
            long long cur = 0;
            for (int i = 1; i * num2 <= mx; i++) {
                int val = i * num2;
                if (m1.contains(val)) {
                    cur += m1[val];
                }
            }
            res += cur * count;
        }
        return res;
    }
};
```
