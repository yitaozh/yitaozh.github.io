---
title: 3180. Maximum Total Reward Using Operations I
categories: Leetcode
date: 2024-06-14 14:09:50
tags:
    - Array
    - Dynamic Programming
---

[3180. Maximum Total Reward Using Operations I](https://leetcode.com/problems/maximum-total-reward-using-operations-i/description/)

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
```

Explanation:

During the operations, we can choose to mark the indices 0 and 2 in order, and the total reward will be 4, which is the maximum.

**Example 2:**

```bash
Input: rewardValues = [1,6,4,3,2]

Output: 11
```

Explanation:

Mark the indices 0, 2, and 1 in order. The total reward will then be 11, which is the maximum.

**Constraints:**

- `1 <= rewardValues.length <= 2000`
- `1 <= rewardValues[i] <= 2000`

## Hints/Notes

- Weekly Contest 401
- dp

## Solution

Language: **C++**

```C++
class Solution {
public:
    int ans = INT_MIN;
    map<int, int> m;

    int maxTotalReward(vector<int>& rewardValues) {
        set<int> s(rewardValues.begin(), rewardValues.end());
        traverse(0, s);
        return ans;
    }

    int traverse(int curValue, set<int>& s) {
        if (s.lower_bound(curValue + 1) == s.end()) {
            ans = max(ans, curValue);
            return 0;
        }

        if (m.contains(curValue)) {
            return m[curValue];
        }

        int res = 0;
        for (auto it = s.lower_bound(curValue); it != s.end(); it++) {
            if (*it == curValue) {
                continue;
            }
            res = max(res, traverse(curValue + *it, s));
        }
        m[curValue] = res;
        return res;
    }
};
```
