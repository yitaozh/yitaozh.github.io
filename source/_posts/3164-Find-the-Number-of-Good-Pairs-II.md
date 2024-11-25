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
- [0x3F's solution](https://leetcode.cn/problems/find-the-number-of-good-pairs-ii/solutions/2790631/tong-ji-yin-zi-ge-shu-pythonjavacgo-by-e-bl3o/)
- Weekly Contest 399

## Solution

Language: **C++**

```C++
class Solution {
public:
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<int> candidates;
        unordered_map<int, int> m;
        unordered_map<int, int> nums2map;
        for (int i = 0; i < nums1.size(); i++) {
            if (nums1[i] % k == 0) {
                candidates.push_back(nums1[i] / k);
                m[nums1[i] / k]++;
            }
        }
        sort(candidates.begin(), candidates.end());
        sort(nums2.begin(), nums2.end());
        long long res = 0;
        if (candidates.empty()) {
            return res;
        }
        for (int num2 : nums2) {
            if (nums2map.contains(num2)) {
                res += nums2map[num2];
                continue;
            }
            long index = 1;
            int cur = 0;
            while (index * num2 <= candidates.back()) {
                if (m.contains(index * num2)) {
                    res += m[index * num2];
                    cur += m[index * num2];
                }
                index++;
            }
            nums2map[num2] = cur;
        }
        return res;
    }
};
```
