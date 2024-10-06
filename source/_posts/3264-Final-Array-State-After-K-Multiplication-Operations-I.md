---
title: 3264. Final Array State After K Multiplication Operations I
categories: Leetcode
date: 2024-10-06 15:43:19
tags:
    - Array
    - Math
    - Heap (Priority Queue)
    - Simulation
---

[3264. Final Array State After K Multiplication Operations I](https://leetcode.com/problems/final-array-state-after-k-multiplication-operations-i/description/)

## Description

You are given an integer array `nums`, an integer `k`, and an integer `multiplier`.

You need to perform `k` operations on `nums`. In each operation:

- Find the **minimum**  value `x` in `nums`. If there are multiple occurrences of the minimum value, select the one that appears **first** .
- Replace the selected minimum value `x` with `x * multiplier`.

Return an integer array denoting the final state of `nums` after performing all `k` operations.

**Example 1:**

```bash
Input: nums = [2,1,3,5,6], k = 5, multiplier = 2

Output: [8,4,6,5,6]
```

Explanation:

<table><tbody><tr><th>Operation</th><th>Result</th></tr><tr><td>After operation 1</td><td>[2, 2, 3, 5, 6]</td></tr><tr><td>After operation 2</td><td>[4, 2, 3, 5, 6]</td></tr><tr><td>After operation 3</td><td>[4, 4, 3, 5, 6]</td></tr><tr><td>After operation 4</td><td>[4, 4, 6, 5, 6]</td></tr><tr><td>After operation 5</td><td>[8, 4, 6, 5, 6]</td></tr></tbody></table>

**Example 2:**

```bash
Input: nums = [1,2], k = 3, multiplier = 4

Output: [16,8]
```

Explanation:

<table><tbody><tr><th>Operation</th><th>Result</th></tr><tr><td>After operation 1</td><td>[4, 2]</td></tr><tr><td>After operation 2</td><td>[4, 8]</td></tr><tr><td>After operation 3</td><td>[16, 8]</td></tr></tbody></table>

**Constraints:**

- `1 <= nums.length <= 100`
- `1 <= nums[i] <= 100`
- `1 <= k <= 10`
- `1 <= multiplier <= 5`

## Hints/Notes

- priority queue

## Solution

Language: **C++**

```C++
class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>>
            pq;
        for (int i = 0; i < nums.size(); i++) {
            pq.push({nums[i], i});
        }
        for (int i = 0; i < k; i++) {
            auto v = pq.top();
            pq.pop();
            pq.push({v[0] * multiplier, v[1]});
        }
        vector<int> res(nums.size());
        while (!pq.empty()) {
            auto v = pq.top();
            pq.pop();
            int idx = v[1], val = v[0];
            res[idx] = val;
        }
        return res;
    }
};
```
