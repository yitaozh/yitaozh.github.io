---
title: 3413. Maximum Coins From K Consecutive Bags
categories: Leetcode
date: 2025-01-15 00:06:31
tags:
    - Array
    - Binary Search
    - Greedy
    - Sliding Window
    - Sorting
    - Prefix Sum
---

[3413. Maximum Coins From K Consecutive Bags](https://leetcode.com/problems/maximum-coins-from-k-consecutive-bags/description/)

## Description

There are an infinite amount of bags on a number line, one bag for each coordinate. Some of these bags contain coins.

You are given a 2D array `coins`, where coins[i] = [l<sub>i</sub>, r<sub>i</sub>, c<sub>i</sub>] denotes that every bag from l<sub>i</sub> to r<sub>i</sub> contains c<sub>i</sub> coins.

The segments that `coins` contain are non-overlapping.

You are also given an integer `k`.

Return the **maximum**  amount of coins you can obtain by collecting `k` consecutive bags.

**Example 1:**

```bash
Input: coins = [[8,10,1],[1,3,2],[5,6,4]], k = 4

Output: 10
```

Explanation:

Selecting bags at positions `[3, 4, 5, 6]` gives the maximum number of coins:`2 + 0 + 4 + 4 = 10`.

**Example 2:**

```bash
Input: coins = [[1,10,3]], k = 2

Output: 6
```

Explanation:

Selecting bags at positions `[1, 2]` gives the maximum number of coins:`3 + 3 = 6`.

**Constraints:**

- `1 <= coins.length <= 10^5`
- `1 <= k <= 10^9`
- coins[i] == [l<sub>i</sub>, r<sub>i</sub>, c<sub>i</sub>]
- 1 <= l<sub>i</sub> <= r<sub>i</sub> <= 10^9
- 1 <= c<sub>i</sub> <= 1000
- The given segments are non-overlapping.

## Hints/Notes

- 2025/01/13
- sort and sliding window
- [0x3F's solution](https://leetcode.cn/problems/maximum-coins-from-k-consecutive-bags/solutions/3039059/hua-dong-chuang-kou-hua-liang-bian-pytho-4u47/)(checked)
- Weekly Contest 431

## Solution

Language: **C++**

```C++
class Solution {
public:
    long long maximumCoins(vector<vector<int>>& coins, int k) {
        ranges::sort(coins);
        long long res1 = maximum(coins, k);
        for (auto& coin : coins) {
            swap(coin[0], coin[1]);
            coin[0] *= -1;
            coin[1] *= -1;
        }
        reverse(coins.begin(), coins.end());
        long long res2 = maximum(coins, k);
        return max(res1, res2);
    }

    long long maximum(vector<vector<int>>& coins, int k) {
        int left = 0, n = coins.size();
        long long cur = 0, res = 0;
        for (int i = 0; i < n; i++) {
            int right = coins[i][1] + 1, weight = coins[i][2];
            cur += (long long)(coins[i][1] - coins[i][0] + 1) * weight;
            // at this step, we moved tiles out of the carpet, whose
            // right side is less than (right - carpetLen)
            while (coins[left][1] < right - k) {
                int w = coins[left][2];
                cur -= (long long)(coins[left][1] - coins[left][0] + 1) * w;
                left++;
            }
            // now it's possible that the left is out of the carpet
            if (coins[left][0] < right - k) {
                int w = coins[left][2];
                res = max(res, cur - (long long)(right - k - coins[left][0]) * w);
            } else {
                res = max(res, cur);
            }
        }
        return res;
    }
};
```
