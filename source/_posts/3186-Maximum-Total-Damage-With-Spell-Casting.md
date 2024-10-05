---
title: 3186. Maximum Total Damage With Spell Casting
categories: Leetcode
date: 2024-06-19 00:37:44
tags:
    - Array
    - Hash Table
    - Two Pointers
    - Binary Search
    - Dynamic Programming
    - Sorting
    - Counting
---

[3186. Maximum Total Damage With Spell Casting](https://leetcode.com/problems/maximum-total-damage-with-spell-casting/description/)

## Description

A magician has various spells.

You are given an array `power`, where each element represents the damage of a spell. Multiple spells can have the same damage value.

It is a known fact that if a magician decides to cast a spell with a damage of `power[i]`, they **cannot**  cast any spell with a damage of `power[i] - 2`, `power[i] - 1`, `power[i] + 1`, or `power[i] + 2`.

Each spell can be cast **only once**.

Return the **maximum**  possible total damage that a magician can cast.

**Example 1:**

```bash
Input: power = [1,1,3,4]

Output: 6

Explanation:

The maximum possible damage of 6 is produced by casting spells 0, 1, 3 with damage 1, 1, 4.
```

**Example 2:**

```bash
Input: power = [7,1,6,6]

Output: 13

Explanation:

The maximum possible damage of 13 is produced by casting spells 1, 2, 3 with damage 1, 6, 6.
```

**Constraints:**

- `1 <= power.length <= 10^5`
- `1 <= power[i] <= 10^9`

## Hints/Notes

- Weekly Contest 402

## Solution

Language: **C++**

```C++
class Solution {
public:
    int size_;
    vector<long long> dp;

    long long maximumTotalDamage(vector<int>& power) {
        sort(power.begin(), power.end());
        vector<pair<int, int>> pairs;
        for (int i = 0; i < power.size(); i++) {
            int count = 1;
            while (i + 1 < power.size() && power[i] == power[i + 1]) {
                i++;
                count++;
            }
            pairs.push_back({power[i], count});
        }
        size_ = pairs.size();
        dp.resize(size_, LLONG_MIN);
        long long ans = dfs(0, pairs);
        return ans;
    }

    long long dfs(int curIndex, vector<pair<int, int>>& pairs) {
        if (curIndex == size_) {
            return 0;
        }
        if (dp[curIndex] != LLONG_MIN) {
            return dp[curIndex];
        }
        long long val = pairs[curIndex].first;

        long long firstRes = val * pairs[curIndex].second;
        int nextIndex = curIndex;
        while (nextIndex < size_ && pairs[nextIndex].first - val <= 2) {
            nextIndex++;
        }
        firstRes += dfs(nextIndex, pairs);

        if (curIndex == pairs.size() - 1 ||
            (pairs[curIndex + 1].first - pairs[curIndex].first > 2)) {
            dp[curIndex] = firstRes;
            return firstRes;
        }
        long long secondRes = dfs(curIndex + 1, pairs);
        dp[curIndex] = max(firstRes, secondRes);
        return dp[curIndex];
    }
};
```
