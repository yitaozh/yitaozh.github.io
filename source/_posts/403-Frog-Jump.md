---
title: 403. Frog Jump
categories: Leetcode
date: 2025-03-16 21:58:24
tags:
    - Array
    - Dynamic Programming
---

[403. Frog Jump](https://leetcode.com/problems/frog-jump/description/?envType=company&envId=snapchat&favoriteSlug=snapchat-more-than-six-months)

## Description

A frog is crossing a river. The river is divided into some number of units, and at each unit, there may or may not exist a stone. The frog can jump on a stone, but it must not jump into the water.

Given a list of `stones`positions (in units) in sorted **ascending order** , determine if the frog can cross the river by landing on the last stone. Initially, the frog is on the first stone and assumes the first jump must be `1` unit.

If the frog's last jump was `k` units, its next jump must be either `k - 1`, `k`, or `k + 1` units. The frog can only jump in the forward direction.

**Example 1:**

```bash
Input: stones = [0,1,3,5,6,8,12,17]
Output: true
Explanation: The frog can jump to the last stone by jumping 1 unit to the 2nd stone, then 2 units to the 3rd stone, then 2 units to the 4th stone, then 3 units to the 6th stone, 4 units to the 7th stone, and 5 units to the 8th stone.
```

**Example 2:**

```bash
Input: stones = [0,1,2,3,4,8,9,11]
Output: false
Explanation: There is no way to jump to the last stone as the gap between the 5th and 6th stone is too large.
```

**Constraints:**

- `2 <= stones.length <= 2000`
- `0 <= stones[i] <= 2^31 - 1`
- `stones[0] == 0`
- `stones`is sorted in a strictly increasing order.

## Hints/Notes

- 2025/02/09 Q3
- dp
- [Leetcode solution](https://leetcode.com/problems/frog-jump/editorial/?envType=company&envId=snapchat&favoriteSlug=snapchat-more-than-six-months)

## Solution

Language: **C++**

```C++
class Solution {
public:
    unordered_set<int> s;
    unordered_map<int, unordered_map<int, bool>> dp;
    int target;

    bool canCross(vector<int>& stones) {
        target = stones.back();
        s = unordered_set<int>(stones.begin(), stones.end());
        bool res = dfs(0, 1);
        return res;
    }

    bool dfs(int pos, int jump) {
        if (pos == target) {
            return true;
        }
        if (pos > target) {
            return false;
        }
        if (dp[pos].contains(jump)) {
            return dp[pos][jump];
        }
        bool res = false;
        if (s.contains(pos + jump)) {
            for (int i = max(1, jump - 1); i <= jump + 1; i++) {
                res |= dfs(pos + jump, i);
                if (res) {
                    break;
                }
            }
        }
        dp[pos][jump] = res;
        return res;
    }
};
```
