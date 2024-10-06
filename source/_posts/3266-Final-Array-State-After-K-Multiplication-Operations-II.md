---
title: 3266. Final Array State After K Multiplication Operations II
categories: Leetcode
date: 2024-10-06 16:07:08
tags:
    - Array
    - Heap (Priority Queue)
    - Simulation
---

[3266. Final Array State After K Multiplication Operations II](https://leetcode.com/problems/final-array-state-after-k-multiplication-operations-ii/description/)

## Description

You are given an integer array `nums`, an integer `k`, and an integer `multiplier`.

You need to perform `k` operations on `nums`. In each operation:

- Find the **minimum**  value `x` in `nums`. If there are multiple occurrences of the minimum value, select the one that appears **first** .
- Replace the selected minimum value `x` with `x * multiplier`.

After the `k` operations, apply **modulo**  `10^9 + 7` to every value in `nums`.

Return an integer array denoting the final state of `nums` after performing all `k` operations and then applying the modulo.

**Example 1:**

<div class="example-block">
Input: nums = [2,1,3,5,6], k = 5, multiplier = 2

Output: [8,4,6,5,6]

Explanation:

<table><tbody><tr><th>Operation</th><th>Result</th></tr><tr><td>After operation 1</td><td>[2, 2, 3, 5, 6]</td></tr><tr><td>After operation 2</td><td>[4, 2, 3, 5, 6]</td></tr><tr><td>After operation 3</td><td>[4, 4, 3, 5, 6]</td></tr><tr><td>After operation 4</td><td>[4, 4, 6, 5, 6]</td></tr><tr><td>After operation 5</td><td>[8, 4, 6, 5, 6]</td></tr><tr><td>After applying modulo</td><td>[8, 4, 6, 5, 6]</td></tr></tbody></table>

**Example 2:**

<div class="example-block">
Input: nums = [100000,2000], k = 2, multiplier = 1000000

Output: [999999307,999999993]

Explanation:

<table><tbody><tr><th>Operation</th><th>Result</th></tr><tr><td>After operation 1</td><td>[100000, 2000000000]</td></tr><tr><td>After operation 2</td><td>[100000000000, 2000000000]</td></tr><tr><td>After applying modulo</td><td>[999999307, 999999993]</td></tr></tbody></table>

**Constraints:**

- `1 <= nums.length <= 10^4`
- `1 <= nums[i] <= 10^9`
- `1 <= k <= 10^9`
- `1 <= multiplier <= 10^6`

## Hints/Notes

- find the cycle
- fast power
- Weekly Contest 412

## Solution

Language: **C++**

```C++
class Solution {
public:
    int MOD = 1000000007;

    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        if (multiplier == 1) {
            return nums;
        }
        priority_queue<vector<long>, vector<vector<long>>,
                       greater<vector<long>>>
            pq;
        int maxVal = INT_MIN, n = nums.size();
        for (int i = 0; i < n; i++) {
            maxVal = max(maxVal, nums[i]);
            pq.push({nums[i], i});
        }
        int i = 0;
        for (i = 0; i < k; i++) {
            auto v = pq.top();
            long newVal = v[0] * multiplier;
            // at this moment, the order of the numbers has been fixed,
            // if the remaining number of multiplication is mutiple of n
            // then each item would get the same number of multiplication
            if (newVal > maxVal) {
                // the number of operation we have done: i
                break;
            }
            pq.pop();
            pq.push({newVal, v[1]});
        }
        // the remaining number of operation: k - i
        // every item can get (k - i) / n operations
        // the top (k - i) % n items can get (k - i) / n + 1 operations
        int numOps = (k - i) / n, residue = (k - i) % n;
        vector<int> res(nums.size());
        long mul = fast_exp(multiplier, numOps);
        while (!pq.empty()) {
            auto v = pq.top();
            pq.pop();
            int idx = v[1];
            long val = v[0];
            val = (val * mul) % MOD;
            if (residue > 0) {
                val = (val * multiplier) % MOD;
            }
            residue--;
            res[idx] = val;
        }
        return res;
    }

    int fast_exp(long mul, int n) {
        long res = 1;
        while (n > 0) {
            if (n % 2) {
                res = (res * mul) % MOD;
            }
            mul = (mul * mul) % MOD;
            n >>= 1;
        }
        return res;
    }
};
```
