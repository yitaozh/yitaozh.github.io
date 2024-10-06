---
title: 3273. Minimum Amount of Damage Dealt to Bob
categories: Leetcode
date: 2024-10-06 16:24:41
tags:
    - Array
    - Greedy
    - Sorting
---

[3273. Minimum Amount of Damage Dealt to Bob](https://leetcode.com/problems/minimum-amount-of-damage-dealt-to-bob/description/)

## Description

You are given an integer `power` and two integer arrays `damage` and `health`, both having length `n`.

Bob has `n` enemies, where enemy `i` will deal Bob `damage[i]` **points**  of damage per second while they are alive (i.e. `health[i] > 0`).

Every second, **after**  the enemies deal damage to Bob, he chooses **one**  of the enemies that is still alive and deals `power` points of damage to them.

Determine the **minimum**  total amount of damage points that will be dealt to Bob before **all**  `n` enemies are dead.

**Example 1:**

```bash
Input: power = 4, damage = [1,2,3,4], health = [4,5,6,8]

Output: 39
```

Explanation:

- Attack enemy 3 in the first two seconds, after which enemy 3 will go down, the number of damage points dealt to Bob is `10 + 10 = 20` points.
- Attack enemy 2 in the next two seconds, after which enemy 2 will go down, the number of damage points dealt to Bob is `6 + 6 = 12` points.
- Attack enemy 0 in the next second, after which enemy 0 will go down, the number of damage points dealt to Bob is `3` points.
- Attack enemy 1 in the next two seconds, after which enemy 1 will go down, the number of damage points dealt to Bob is `2 + 2 = 4` points.

**Example 2:**

```bash
Input: power = 1, damage = [1,1,1,1], health = [1,2,3,4]

Output: 20
```

Explanation:

- Attack enemy 0 in the first second, after which enemy 0 will go down, the number of damage points dealt to Bob is `4` points.
- Attack enemy 1 in the next two seconds, after which enemy 1 will go down, the number of damage points dealt to Bob is `3 + 3 = 6` points.
- Attack enemy 2 in the next three seconds, after which enemy 2 will go down, the number of damage points dealt to Bob is `2 + 2 + 2 = 6` points.
- Attack enemy 3 in the next four seconds, after which enemy 3 will go down, the number of damage points dealt to Bob is `1 + 1 + 1 + 1 = 4` points.

**Example 3:**

```bash
Input: power = 8, damage = [40], health = [59]

Output: 320
```

**Constraints:**

- `1 <= power <= 10^4`
- `1 <= n == damage.length == health.length <= 10^5`
- `1 <= damage[i], health[i] <= 10^4`

## Hints/Notes

- Math
- Biweekly Contest 138

## Solution

Language: **C++**

```C++
class Solution {
public:
    long long minDamage(int power, vector<int>& damage, vector<int>& health) {
        long long res = 0;
        int n = damage.size();
        vector<pair<double, int>> pairs;
        // assume we have only 2 pairs of damage and health: h1, d1 and h2, d2
        // if we work on d1 first, and it gives us the smaller damage
        // (d1 + d2) * t1 + d2 * t2 < (d1 + d2) * t2 + d2 * t2
        // => d2 * t1 < d1 * t2 => d1/t1 > d2/t2
        // it means, we should work on the items with larger d/t first
        for (int i = 0; i < n; i++) {
            int t = (health[i] - 1) / power + 1;
            pairs.push_back({(double)damage[i]/ t, i});
        }
        // after the sort, the items are ordered with ascending d/t
        sort(pairs.begin(), pairs.end());
        int totalDamage = 0;
        for (auto p : pairs) {
            int idx = p.second, d = damage[idx], h = health[idx], t = (health[idx] - 1) / power + 1;
            totalDamage += d;
            res += (long)totalDamage * t;
        }
        return res;
    }
};
```
