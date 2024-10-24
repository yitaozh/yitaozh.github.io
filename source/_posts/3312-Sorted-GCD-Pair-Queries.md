---
title: 3312. Sorted GCD Pair Queries
categories: Leetcode
date: 2024-10-19 16:31:04
tags:
    - Array
    - Hash Table
    - Math
    - Binary Search
    - Combinatorics
    - Counting
    - Number Theory
    - Prefix Sum
---

[3312. Sorted GCD Pair Queries](https://leetcode.com/problems/sorted-gcd-pair-queries/description/)

## Description

You are given an integer array `nums` of length `n` and an integer array `queries`.

Let `gcdPairs` denote an array obtained by calculating the GCD of all possible pairs `(nums[i], nums[j])`, where `0 <= i < j < n`, and then sorting these values in **ascending**  order.

For each query `queries[i]`, you need to find the element at index `queries[i]` in `gcdPairs`.

Return an integer array `answer`, where `answer[i]` is the value at `gcdPairs[queries[i]]` for each query.

The term `gcd(a, b)` denotes the **greatest common divisor**  of `a` and `b`.

**Example 1:**

```bash
Input: nums = [2,3,4], queries = [0,2,2]

Output: [1,2,2]
```

Explanation:

`gcdPairs = [gcd(nums[0], nums[1]), gcd(nums[0], nums[2]), gcd(nums[1], nums[2])] = [1, 2, 1]`.

After sorting in ascending order, `gcdPairs = [1, 1, 2]`.

So, the answer is `[gcdPairs[queries[0]], gcdPairs[queries[1]], gcdPairs[queries[2]]] = [1, 2, 2]`.

**Example 2:**

```bash
Input: nums = [4,4,2,1], queries = [5,3,1,0]

Output: [4,2,1,1]
```

Explanation:

`gcdPairs` sorted in ascending order is `[1, 1, 1, 2, 2, 4]`.

**Example 3:**

```bash
Input: nums = [2,2], queries = [0,0]

Output: [2,2]
```

Explanation:

`gcdPairs = [2]`.

**Constraints:**

- `2 <= n == nums.length <= 10^5`
- `1 <= nums[i] <= 5 * 10^4`
- `1 <= queries.length <= 10^5`
- `0 <= queries[i] < n * (n - 1) / 2`

## Hints/Notes

- combinatorics
- Weekly Contest 418

## Solution

Language: **C++**

```C++
class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        int maxVal = 0;
        for (int i = 0; i < nums.size(); i++) {
            maxVal = max(nums[i], maxVal);
        }
        vector<long long> gcd_count(maxVal + 1, 0);
        vector<long long> count(maxVal + 1, 0);
        for (int i = 0; i < nums.size(); i++) {
            count[nums[i]]++;
        }
        // the state transition
        // 2, 4, 6, 8 -> n numbers divisible by 2
        // gcd_count(2) = (n - 1) * n / 2 - gcd_count(4) - gcd_count(6) - ...
        for (int i = maxVal; i >= 1; i--) {
            long long cnt = 0;
            for (int j = i; j <= maxVal; j += i) {
                cnt += count[j];
                gcd_count[i] -= gcd_count[j];
            }
            gcd_count[i] += (cnt - 1) * cnt / 2;
        }
        vector<long long> preSum = {gcd_count[0]};
        for (int i = 1; i <= maxVal; i++) {
            preSum.push_back(preSum.back() + gcd_count[i]);
        }
        // for the second example, the gcd_count looks like
        // 0, 3, 2, 0, 1
        // the preSum looks like
        // 0, 1, 2, 3, 4
        // 0, 3, 5, 5, 6
        // for queries [5,3,1,0]
        // we are finding the right most value that can suit the need
        vector<int> res;
        for (auto q : queries) {
            int l = 0, r = preSum.size();
            while (l < r) {
                int mid = (r - l) / 2 + l;
                if (preSum[mid] == q) {
                    l = mid + 1;
                } else if (preSum[mid] < q) {
                    l = mid + 1;
                } else {
                    r = mid;
                }
            }
            res.push_back(l);
        }
        return res;
    }
};
```
