---
title: 475. Heaters
categories: Leetcode
date: 2025-04-05 23:38:30
tags:
    - Array
    - Two Pointers
    - Binary Search
    - Sorting
---

[475. Heaters](https://leetcode.com/problems/heaters/description/?envType=company&envId=tiktok&favoriteSlug=tiktok-six-months)

## Description

Winter is coming! During the contest, your first job is to design a standard heater with a fixed warm radius to warm all the houses.

Every house can be warmed, as long as the house is within the heater's warm radius range.

Given the positions of `houses` and `heaters` on a horizontal line, return the minimum radius standard of heatersso that those heaters could cover all houses.

**Notice**  thatall the `heaters` follow your radius standard, and the warm radius will the same.

**Example 1:**

```bash
Input: houses = [1,2,3], heaters = [2]
Output: 1
Explanation: The only heater was placed in the position 2, and if we use the radius 1 standard, then all the houses can be warmed.
```

**Example 2:**

```bash
Input: houses = [1,2,3,4], heaters = [1,4]
Output: 1
Explanation: The two heaters were placed at positions 1 and 4. We need to use a radius 1 standard, then all the houses can be warmed.
```

**Example 3:**

```bash
Input: houses = [1,5], heaters = [2]
Output: 3
```

**Constraints:**

- `1 <= houses.length, heaters.length <= 3 * 10^4`
- `1 <= houses[i], heaters[i] <= 10^9`

## Hints/Notes

- 2025/04/05 Q1
- sort + two pointers
- [Leetcode solution](https://leetcode.cn/problems/heaters/solutions/1165760/gong-nuan-qi-by-leetcode-solution-rwui/)

## Solution

Language: **C++**

```C++
class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        ranges::sort(houses);
        ranges::sort(heaters);
        int m = houses.size(), n = heaters.size(), l1 = 0, l2 = 0, radius = 0;
        while (l1 < m) {
            int house = houses[l1], heater = heaters[l2];
            if (house < heater) {
                radius = max(radius, heater - house);
            } else if (house > heater) {
                if (l2 < n - 1) {
                    int next_heater = heaters[l2 + 1];
                    while (l2 < n - 1 && abs(next_heater - house) <= abs(heater - house)) {
                        l2++;
                        heater = heaters[l2];
                        next_heater = heaters[l2 + 1];
                    }
                    radius = max(radius, abs(house - heater));
                } else {
                    radius = max(radius, abs(house - heater));
                }
            }
            l1++;
        }
        return radius;
    }
};
```
