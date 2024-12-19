---
title: 3259. Maximum Energy Boost From Two Drinks
categories: Leetcode
date: 2024-10-03 23:53:21
tags:
    - Array
    - Dynamic Programming
---

[3259. Maximum Energy Boost From Two Drinks](https://leetcode.com/problems/maximum-energy-boost-from-two-drinks/description/)

## Description

You are given two integer arrays `energyDrinkA` and `energyDrinkB` of the same length `n` by a futuristic sports scientist. These arrays represent the energy boosts per hour provided by two different energy drinks, A and B, respectively.

You want to maximize your total energy boost by drinking one energy drink per hour. However, if you want to switch from consuming one energy drink to the other, you need to wait for one hour to cleanse your system (meaning you won't get any energy boost in that hour).

Return the **maximum**  total energy boost you can gain in the next `n` hours.

**Note**  that you can start consuming either of the two energy drinks.

**Example 1:**

```bash
Input: energyDrinkA = [1,3,1], energyDrinkB = [3,1,1]

Output: 5
```

Explanation:

To gain an energy boost of 5, drink only the energy drink A (or only B).

**Example 2:**

```bash
Input: energyDrinkA = [4,1,1], energyDrinkB = [1,1,3]

Output: 7
```

Explanation:

To gain an energy boost of 7:

- Drink the energy drink A for the first hour.
- Switch to the energy drink B and we lose the energy boost of the second hour.
- Gain the energy boost of the drink B in the third hour.

**Constraints:**

- `n == energyDrinkA.length == energyDrinkB.length`
- `3 <= n <= 10^5`
- `1 <= energyDrinkA[i], energyDrinkB[i] <= 10^5`

## Hints/Notes

- 2024/08/19
- dp
- [0x3F's solution](https://leetcode.cn/problems/maximum-energy-boost-from-two-drinks/solutions/2884478/jiao-ni-yi-bu-bu-si-kao-dpcong-ji-yi-hua-iebb/)(checked)
- Weekly Contest 411

## Solution

Language: **C++**

```C++
class Solution {
public:
    vector<vector<long long>> dp;

    long long maxEnergyBoost(vector<int>& energyDrinkA,
                             vector<int>& energyDrinkB) {
        int n = energyDrinkA.size();
        dp.resize(n, vector<long long>(2, -1));
        long long res = max(dfs(0, 0, energyDrinkA, energyDrinkB),
                            dfs(0, 1, energyDrinkA, energyDrinkB));
        return res;
    }

    long long dfs(int index, int cur, vector<int>& energyDrinkA,
                  vector<int>& energyDrinkB) {
        if (index >= energyDrinkA.size()) {
            return 0;
        }
        if (dp[index][cur] != -1) {
            return dp[index][cur];
        }
        long long res = cur ? energyDrinkA[index] : energyDrinkB[index];
        res += max(dfs(index + 1, cur, energyDrinkA, energyDrinkB),
                   dfs(index + 2, 1 - cur, energyDrinkA, energyDrinkB));
        dp[index][cur] = res;
        return res;
    }
};
```
