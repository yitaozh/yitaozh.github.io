---
title: 3196. Maximize Total Cost of Alternating Subarrays
categories: Leetcode
date: 2024-06-27 23:46:47
tags:
    - Array
    - Dynamic Programming
---

[3196. Maximize Total Cost of Alternating Subarrays](https://leetcode.com/problems/maximize-total-cost-of-alternating-subarrays/description/)

## Description

You are given an integer array `nums` with length `n`.

The **cost** of a subarray `nums[l..r]`, where `0 <= l <= r < n`, is defined as:

`cost(l, r) = nums[l] - nums[l + 1] + ... + nums[r] * (−1)^r − l`

Your task is to **split** `nums` into subarrays such that the **total** **cost** of the subarrays is **maximized**, ensuring each element belongs to **exactly one**  subarray.

Formally, if `nums` is split into `k` subarrays, where `k > 1`, at indices i<sub>1</sub>, i<sub>2</sub>, ..., i<sub>k − 1</sub>, where 0 <= i<sub>1</sub> < i<sub>2</sub> < ... < i<sub>k - 1</sub> < n - 1, then the total cost will be:

cost(0, i<sub>1</sub>) + cost(i<sub>1</sub> + 1, i<sub>2</sub>) + ... + cost(i<sub>k − 1</sub> + 1, n − 1)

Return an integer denoting the maximum total cost of the subarrays after splitting the array optimally.

**Note:**  If `nums` is not split into subarrays, i.e. `k = 1`, the total cost is simply `cost(0, n - 1)`.

**Example 1:**

```bash
Input: nums = [1,-2,3,4]

Output: 10

Explanation:

One way to maximize the total cost is by splitting `[1, -2, 3, 4]` into subarrays `[1, -2, 3]` and `[4]`. The total cost will be `(1 + 2 + 3) + 4 = 10`.
```

**Example 2:**

```bash
Input: nums = [1,-1,1,-1]

Output: 4

Explanation:

One way to maximize the total cost is by splitting `[1, -1, 1, -1]` into subarrays `[1, -1]` and `[1, -1]`. The total cost will be `(1 + 1) + (1 + 1) = 4`.
```

**Example 3:**

```bash
Input: nums = [0]

Output: 0

Explanation:

We cannot split the array further, so the answer is 0.
```

**Example 4:**

```bash
Input: nums = [1,-1]

Output: 2

Explanation:

Selecting the whole array gives a total cost of `1 + 1 = 2`, which is the maximum.
```

**Constraints:**

- `1 <= nums.length <= 10^5`
- `-10^9 <= nums[i] <= 10^9`

## Hints/Notes

- Weekly Contest 403

## Solution

Language: **C++**

```C++
class Solution {
public:
    vector<vector<long long>> dp;

    long long maximumTotalCost(vector<int>& nums) {
        int size = nums.size();
        dp.resize(size, vector<long long>(2, LLONG_MIN));
        long long res = traverse(0, true, nums);
        return res;
    }

    long long traverse(int curIndex, bool first, vector<int>& nums) {
        if (curIndex >= dp.size()) {
            return 0;
        }
        if (dp[curIndex][first] != LLONG_MIN) {
            return dp[curIndex][first];
        }

        long long res = first ? nums[curIndex] : -nums[curIndex];

        if (first) {
            res = res + max(traverse(curIndex + 1, true, nums),
                            traverse(curIndex + 1, false, nums));
        } else {
            res = res + traverse(curIndex + 1, true, nums);
        }
        dp[curIndex][first] = res;
        return res;
    }
};
```
