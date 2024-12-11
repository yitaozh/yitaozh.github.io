---
title: 3181. Maximum Total Reward Using Operations II
categories: Leetcode
date: 2024-06-14 14:11:26
tags:
    - Array
    - Dynamic Programming
    - Bit Manipulation
---

[3181. Maximum Total Reward Using Operations II](https://leetcode.com/problems/maximum-total-reward-using-operations-ii/description/)

## Description

You are given an integer array `rewardValues` of length `n`, representing the values of rewards.

Initially, your total reward `x` is 0, and all indices are **unmarked** . You are allowed to perform the following operation **any**  number of times:

- Choose an **unmarked**  index `i` from the range `[0, n - 1]`.
- If `rewardValues[i]` is **greater**  than your current total reward `x`, then add `rewardValues[i]` to `x` (i.e., `x = x + rewardValues[i]`), and **mark**  the index `i`.

Return an integer denoting the **maximum** total reward you can collect by performing the operations optimally.

**Example 1:**

```bash
Input: rewardValues = [1,1,3,3]

Output: 4

Explanation:

During the operations, we can choose to mark the indices 0 and 2 in order, and the total reward will be 4, which is the maximum.
```

**Example 2:**

```bash
Input: rewardValues = [1,6,4,3,2]

Output: 11

Explanation:

Mark the indices 0, 2, and 1 in order. The total reward will then be 11, which is the maximum.
```

**Constraints:**

- `1 <= rewardValues.length <= 5 * 10^4`
- `1 <= rewardValues[i] <= 5 * 10^4`

## Hints/Notes

- 2024/04/09
- bitset
- [0x3F's solution](https://leetcode.cn/problems/maximum-total-reward-using-operations-ii/solutions/2805413/bitset-you-hua-0-1-bei-bao-by-endlessche-m1xn/)(checked)
- Weekly Contest 401

## Solution

Language: **C++**

```C++
class Solution {
public:
    int maxTotalReward(vector<int>& rewardValues) {
        set<int> s(rewardValues.begin(), rewardValues.end());
        bitset<100000> b{1};
        for (int num : s) {
            b |= b << (100000 - num) >> (100000 - num) << num;
        }
        int mx = *ranges::max_element(s);
        for (int i = 2 * mx - 1; i >= 0; i--) {
            if (b.test(i)) {
                return i;
            }
        }
        return 0;
    }
};
```
