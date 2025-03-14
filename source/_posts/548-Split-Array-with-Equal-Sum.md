---
title: 548. Split Array with Equal Sum
categories: Leetcode
date: 2025-03-14 13:37:52
tags:
    - Array
    - Hash Table
    - Prefix Sum
---

[548. Split Array with Equal Sum](https://leetcode.com/problems/split-array-with-equal-sum/description/)

## Description

Given an integer array `nums` of length `n`, return `true` if there is a triplet `(i, j, k)` which satisfies the following conditions:

- `0 < i, i + 1 < j, j + 1 < k < n - 1`
- The sum of subarrays `(0, i - 1)`, `(i + 1, j - 1)`, `(j + 1, k - 1)` and `(k + 1, n - 1)` is equal.

A subarray `(l, r)` represents a slice of the original array starting from the element indexed `l` to the element indexed `r`.

**Example 1:**

```bash
Input: nums = [1,2,1,2,1,2,1]
Output: true
Explanation:
i = 1, j = 3, k = 5.
sum(0, i - 1) = sum(0, 0) = 1
sum(i + 1, j - 1) = sum(2, 2) = 1
sum(j + 1, k - 1) = sum(4, 4) = 1
sum(k + 1, n - 1) = sum(6, 6) = 1
```

**Example 2:**

```bash
Input: nums = [1,2,1,2,1,2,1,2]
Output: false
```

**Constraints:**

- `n ==nums.length`
- `1 <= n <= 2000`
- `-10^6 <= nums[i] <= 10^6`

## Hints/Notes

- 2025/02/03 Q3
- preSum
- [Leetcode solution](https://leetcode.com/problems/split-array-with-equal-sum/editorial/)

## Solution

Language: **C++**

```C++
class Solution {
public:
    bool splitArray(vector<int>& nums) {
        int n = nums.size();
        if (n < 7) {
            return false;
        }
        vector<int> preSum(n, 0);
        preSum[0] = nums[0];
        for (int i = 1; i < n; i++) {
            preSum[i] = preSum[i - 1] + nums[i];
        }
        for (int j = 3; j < nums.size() - 3; j++) {
            unordered_set<int> s;
            for (int i = 1; i + 1 < j; i++) {
                if (preSum[i - 1] == preSum[j - 1] - preSum[i]) {
                    s.insert(preSum[i - 1]);
                }
            }
            if (s.empty()) {
                continue;
            }
            for (int k = j + 2; k < n - 1; k++) {
                if ((preSum[k - 1] - preSum[j] == preSum[n - 1] - preSum[k]) && s.contains(preSum[k - 1] - preSum[j])) {
                    return true;
                }
            }
        }
        return false;
    }
};
```
