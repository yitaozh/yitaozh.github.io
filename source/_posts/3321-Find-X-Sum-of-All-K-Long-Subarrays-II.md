---
title: 3321. Find X-Sum of All K-Long Subarrays II
categories: Leetcode
date: 2024-10-21 15:37:30
tags:
    - Array
    - Hash Table
    - Sliding Window
    - Heap (Priority Queue)
---

[3321. Find X-Sum of All K-Long Subarrays II](https://leetcode.com/problems/find-x-sum-of-all-k-long-subarrays-ii/description/)

## Description

You are given an array `nums` of `n` integers and two integers `k` and `x`.

The **x-sum**  of an array is calculated by the following procedure:

- Count the occurrences of all elements in the array.
- Keep only the occurrences of the top `x` most frequent elements. If two elements have the same number of occurrences, the element with the **bigger**  value is considered more frequent.
- Calculate the sum of the resulting array.

**Note**  that if an array has less than `x` distinct elements, its **x-sum**  is the sum of the array.

Return an integer array `answer` of length `n - k + 1` where `answer[i]` is the **x-sum**  of the subarray `nums[i..i + k - 1]`.

**Example 1:**

```bash
Input: nums = [1,1,2,2,3,4,2,3], k = 6, x = 2

Output: [6,10,12]
```

Explanation:

- For subarray `[1, 1, 2, 2, 3, 4]`, only elements 1 and 2 will be kept in the resulting array. Hence, `answer[0] = 1 + 1 + 2 + 2`.
- For subarray `[1, 2, 2, 3, 4, 2]`, only elements 2 and 4 will be kept in the resulting array. Hence, `answer[1] = 2 + 2 + 2 + 4`. Note that 4 is kept in the array since it is bigger than 3 and 1 which occur the same number of times.
- For subarray `[2, 2, 3, 4, 2, 3]`, only elements 2 and 3 are kept in the resulting array. Hence, `answer[2] = 2 + 2 + 2 + 3 + 3`.

**Example 2:**

```bash
Input: nums = [3,8,7,8,7,5], k = 2, x = 2

Output: [11,15,15,15,12]
```

Explanation:

Since `k == x`, `answer[i]` is equal to the sum of the subarray `nums[i..i + k - 1]`.

**Constraints:**

- `nums.length == n`
- `1 <= n <= 10^5`
- `1 <= nums[i] <= 10^9`
- `1 <= x <= k <= nums.length`

## Hints/Notes

- sliding window with 2 sorted lists
- pair in cpp can be compared

## Solution

Language: **C++**

```C++
class Solution {
public:
    vector<long long> findXSum(vector<int>& nums, int k, int x) {
        set<pair<int, long long>> mx, mi;
        unordered_map<int, int> m;
        vector<long long> res;
        int n = nums.size(), left = 0, right = 0;
        long long cur = 0;
        for (int i = 0; i <= n - k; i++) {
            pair<int, long long> p;
            while (right < i + k) {
                int r = nums[right];
                if (m[r] > 0) {
                    p = make_pair(m[r], r);
                    if (mx.contains(p)) {
                        cur -= p.first * p.second;
                        mx.erase(p);
                    } else {
                        mi.erase(p);
                    }
                    p.first++;
                } else {
                    p = make_pair(1, r);
                }
                cur += p.first * p.second;
                m[r] = p.first;
                mx.insert(p);
                right++;
            }
            while (mx.size() > x) {
                auto it = mx.begin();
                p = *it;
                mx.erase(it);
                mi.insert(p);
                cur -= p.first * p.second;
            }
            res.push_back(cur);
            int l = nums[i];
            p = make_pair(m[l], l);
            if (mx.contains(p)) {
                mx.erase(p);
                cur -= p.first * p.second;
            } else {
                mi.erase(p);
            }
            p.first--;
            m[l]--;
            if (m[l] > 0) {
                mi.insert(p);
            }
            if (mx.size() < x && !mi.empty()) {
                auto it = prev(mi.end());
                p = *it;
                mi.erase(it);
                mx.insert(p);
                cur += p.first * p.second;
            }
        }
        return res;
    }
};
```
