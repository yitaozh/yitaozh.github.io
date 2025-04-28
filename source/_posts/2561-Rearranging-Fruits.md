---
title: 2561. Rearranging Fruits
categories: Leetcode
date: 2025-04-27 23:42:28
tags:
    - Array
    - Hash Table
    - Greedy
---

[2561. Rearranging Fruits](https://leetcode.com/problems/rearranging-fruits/description/?envType=company&envId=tiktok&favoriteSlug=tiktok-six-months)

## Description

You have two fruit baskets containing `n` fruits each. You are given two **0-indexed**  integer arrays `basket1` and `basket2` representing the cost of fruit in each basket. You want to make both baskets **equal** . To do so, you can use the following operation as many times as you want:

- Chose two indices `i` and `j`, and swap the `i<font size="1">th`fruit of `basket1` with the `j<font size="1">th`fruit of `basket2`.
- The cost of the swap is `min(basket1[i],basket2[j])`.

Two baskets are considered equal if sorting them according to the fruit cost makes them exactly the same baskets.

Return the minimum cost to make both the baskets equal or `-1` if impossible.

**Example 1:**

```bash
Input: basket1 = [4,2,2,2], basket2 = [1,4,1,2]
Output: 1
Explanation: Swap index 1 of basket1 with index 0 of basket2, which has cost 1. Now basket1 = [4,1,2,2] and basket2 = [2,4,1,2]. Rearranging both the arrays makes them equal.
```

**Example 2:**

```bash
Input: basket1 = [2,3,4,1], basket2 = [3,2,5,1]
Output: -1
Explanation: It can be shown that it is impossible to make both the baskets equal.
```

**Constraints:**

- `basket1.length == basket2.length`
- `1 <= basket1.length <= 10^5`
- `1 <= basket1[i],basket2[i]<= 10^9`

## Hints/Notes

- 2025/04/25 Q2
- greedy
- [0x3F's solution](https://leetcode.cn/problems/rearranging-fruits/solutions/2093878/tan-xin-gou-zao-by-endlesscheng-c2ui/)

## Solution

Language: **C++**

```C++
class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        map<int, int> count, count1;
        for (auto num : basket1) {
            count1[num]++;
            count[num]++;
        }
        for (auto num : basket2) {
            count[num]++;
        }
        int total = 0;
        for (auto [k, v] : count) {
            if (v % 2) {
                return -1;
            }
            total += abs(v / 2 - count1[k]);
        }
        total /= 2;
        long long res = 0;
        if (total == 0) {
            return res;
        }
        int min_val = min(ranges::min(basket1), ranges::min(basket2));
        // so for each [k, v] pair in count, we should have v/2 numbers in count1
        // for a specific k:
        // 1. if v1 > v / 2, then it means we need to swap it out
        // 2. if v1 < v / 2, then it means we need to swap a number in
        for (auto [k, v] : count) {
            int target = v / 2, cur = count1[k];
            if (target != cur) {
                int diff = abs(target - cur);
                res += (long)min(total, diff) * min(k, 2 * min_val);
                total = max(0, total - diff);
                if (total == 0) {
                    return res;
                }
            }
        }
        return -1;
    }
};
```
